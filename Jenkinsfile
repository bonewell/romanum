pipeline {
  agent any

  stages {
    stage('Build') {
      steps {
        sh 'mkdir -p build && cd build && cmake .. && make'
      }
    }
    stage('Test') {
      steps {
        sh 'make test'
      }
    }
  }
}
