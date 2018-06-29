pipeline {
  agent any

  stages {
    stage('Build') {
      steps {
        sh 'mkdir build && cd build'
        sh 'cmake .. && make'
      }
    }
    stage('Test') {
      steps {
        sh 'make test'
      }
    }
  }
}
