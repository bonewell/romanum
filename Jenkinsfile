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
        sh 'cd build && GTEST_OUTPUT="xml:report.xml" ctest'
        junit '**/report.xml'
      }
    }
    stage('Build Qt GUI') {
      steps {
        sh 'mkdir -p build-qt-gui && cd build-qt-gui && qmake ../qt-gui && make'
      }
    }
  }
}
