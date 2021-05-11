# Distributed Data Processing

## Mapreduce
- Mapreduce는 Batch Processing System : 순차적 실행 시스템
- 하지만, 인터랙티브한 분석에 적합하지 않음
- 하둡v2의 YARN은 다른 프로세싱 패러다임을 사용하는 FW를 사용할 수 있도록 함

## Hadoop v2를 쓰는 이유
- 반복적 계산 
- 인터랙티브 SQL 
- 스트림 프로세싱  
- 검색


# Hadoop Framwork
## Apache Spark
- 고성능 분산 컴퓨팅 FW
- 인메모리 스토리지 모드와 장애 복구 능력(장애에 대한 적응성)을 가짐

## Apache Hive
- SQL 인터페이스 제공
- Mapreduce를 사용한 프로그램을 작성하지 않고 HDFS 데이터를 사용할 수 있음
- DataBase는 아니지만, 메커니즘을 제공하고, 쿼리를 처리할 수 있음
- SQL을 사용하여 인터랙티브하게 데이터베이스에 저장된 데이터 쿼리를 처리하는 방식

## Apache Pig
- Spark, Hive와 함께 사용
- 절차식 언어

# Virtual Distributed Cluster
## Utility
### Red Hat
- yum : Red Hat Emterprise Linux RPM
- rpm : Red Hat, SUSE, Fedora
### All OS
- scp : 호스트 사이에서 안전하게 파일과 디렉토리를 복사 
- curl : URL을 이용하여 파일을 보내고 받음
- wget : HTTP or FTP 프로토콜을 사용하여 파일을 가져옴
- pdsh : 명령을 원격으로 실행

## Setting
    > ulimit [-Sn] [-Hn]
    > sysctl [-p] [-a]
    > hdparm [-t] /dev/sda1
