pipeline
{
  agent none

  stages
  {
    stage("Build")
    {
      parallel
      {

        stage ('gnu48')
        {
          agent any
          steps
          {

            sh "echo \"building on node ${env.NODE_NAME}\""
            sh '''#!/bin/bash
             set -e
             export NP=`grep -c ^processor /proc/cpuinfo`
             mkdir -p build
             cd build
             cmake $WORKSPACE/
             time make -j $NP
             time make test
            '''
          }

          post 
          {
            cleanup 
            {
              cleanWs()
            }
          }
        } // stage gnu48

        stage ('gnu8')
        {
          agent any
          steps
          {

            sh "echo \"building on node ${env.NODE_NAME}\""
            sh '''#!/bin/bash
             set -e
             export NP=`grep -c ^processor /proc/cpuinfo`
             mkdir -p build
             cd build
             cmake -DCMAKE_CXX_COMPILER=g++-8 $WORKSPACE/
             time make -j $NP
             time make test
            '''
          }

          post 
          {
            cleanup 
            {
              cleanWs()
            }
          }
        } // stage gnu8

    } // parallel   

      post 
      {
        success {
          emailext (
            subject: "SUCCESSFUL: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]'",
            mimeType: 'text/html',
            from: 'jenkins@wias-berlin.de',
            body: """<p>SUCCESSFUL: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]':</p>
              <p>Check console output at &QUOT;<a href='${env.BUILD_URL}'>${env.JOB_NAME} [${env.BUILD_NUMBER}]</a>&QUOT;</p>""",
            recipientProviders: [[$class: 'CulpritsRecipientProvider']]
            )
        } // success
      } // post email
    } // stage build
  } // stages
} // pipeline
