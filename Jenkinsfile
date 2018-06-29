pipeline {
  agent any

  stages {
    stage('Build') {
      sh 'mkdir build && cd build'
      sh 'cmake .. && make'
    }
    stage('Test') {
    }
  }
}
