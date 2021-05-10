# Hadoop Download and Setting

## Environment
\## ubuntu 18.04.5 LTS  
\## VMware Workstation 16 Player  

## Terminal command
### JAVA Install (openjdk 8) 
    $ sudo apt-get update
    $ sudo apt-get purge openjdk*
    $ sudo add-apt-repository ppa:webupd8team/java
    $ sudo apt-get update
    $ sudo apt-get install openjdk-8-jdk -y
    $ java -version

### JAVA Setting
    $ sudo gedit /etc/profile
        // add last line
        export JAVA_HOME=/usr/local/java
        export PATH=$PATH:$JAVA_HOME/bin
        export CLASS_PATH="."
    $ source /etc/profile

### Network Setting
    $ sudo gedit /etc/sysctl.conf
        // add last line
        #disable ipv6
        net.ipv6.conf.all.disable_ipv6 = 1
        net.ipv6.conf.default.disable_ipv6 = 1
        net.ipv6.conf.lo.disable_ipv6 = 1
    $ sudo reboot
    

### Hadoop User
    $ sudo addgroup hadoopgroup
    $ sudo adduser -ingroup hadoopgroup hduser
    
    $ sudo apt-get install ssh -y
    $ sudo systemctl enable ssh
    $ sudo systemctl start ssh
    
    $ su - hduser
    $ ssh-keygen -t rsa -P ""
    $ cat /home/hduser/.ssh/id_rsa.pub >> /home/hduser/.ssh/authorized_keys
    $ cd .ssh/
    $ chmod 600 ./authorized_keys
    $ ssh-copy-id -i /home/hduser/.ssh/id_rsa.pub localhost -yes
    $ ssh localhost
    $ exit
    $ exit

    $ sudo gedit /etc/sudoers
        // root ALL=(ALL:ALL) ALL 밑에 추가하기
        hduser ALL=(ALL:ALL) ALL
        
### Install Hadoop(v.2.10.0)
    $ su - hduser
    $ wget https://archive.apache.org/dist/hadoop/common/hadoop-2.10.0/hadoop-2.10.0.tar.gz
    $ tar -xvf hadoop-2.10.0.tar.gz
    $ cd /home/hduser
    $ sudo mv ./hadoop-2.10.0 /usr/local/
    $ sudo ln -sf /usr/local/hadoop-2.10.0/ /usr/local/hadoop
    $ sudo chown -R hduser:hadoopgroup /usr/local/hadoop-2.10.0/
    $ su - hduser

### Hadoop Setting
    $ sudo vi ./.bashrc
        #Hadoop config
        export HADOOP_PREFIX=/usr/local/hadoop
        export HADOOP_HOME=/usr/local/hadoop
        export HADOOP_MAPRED_HOME=${HADOOP_HOME}
        export HADOOP_COMMON_HOME=${HADOOP_HOME}
        export HADOOP_HDFS_HOME=${HADOOP_HOME}
        export YARN_HOME=${HADOOP_HOME}
        export HADOOP_CONF_DIR=${HADOOP_HOME}/etc/hadoop
        #Native path
        export HADOOP_COMMON_LIB_NATIVE_DIR=${HADOOP_HOME}/lib/native
        export HADOOP_OPT="-Djava.library.path=$HADOOP_PREFIX/lib/native"
        #Java path
        export JAVA_HOME="/usr"
        #OS path
        export PATH=$PATH:$HADOOP_HOME/bin:$JAVA_HOME/bin:$HADOOP_HOME/sbin
    $ source ./.bashrc
    
    $ sudo vim /usr/local/hadoop/etc/hadoop/hadoop-env.sh
        // export JAVA_HOME=${JAVA_HOME} 밑에 추가하기
        export JAVA_HOME="/usr"
    
### Hadoop Configuration Setting
    $ cd /usr/local/hadoop/etc/hadoop
    
    // <configuration> ~내용입력~ </configuration>
    $ sudo gedit core-site.xml
        <property>
            <name>fs.default.name</name>
            <value>hdfs://localhost:9000</value>
        </property>
    
    # sudo gedit hdfs-site.xml
        <property>
            <name>dfs.replication</name>
            <value>1</value>
        </property>
        <property>
            <name>dfs.name.dir</name>
            <value>file:/usr/local/hadoop/hadoopdata/hdfs/namenode</value>
        </property>
        <property>
            <name>dfs.data.dir</name>
            <value>file:/usr/local/hadoop/hadoopdata/hdfs/datanode</value>
        </property>

    $ sudo gedit mapred-site.xml.template
        <property>
            <name>mapreduce.framework.name</name>
            <value>yarn</value>
        </property>
        
        
    $ sudo apt-get install rename
    $ sudo rename 's/mapred-site.xml.template$/mapred-site.xml/' ^
    
    $ sudo gedit yarn-site.xml
        <property>
            <name>yarn.nodemanager.aux-services</name>
            <value>mapreduce_shuffle</value>
        </property>

### Launch
    $ cd ../../bin
    $ hdfs namenode -format
    $ cd /home/hduser/
    $ start-dfs.sh
    $ start-yarn.sh
    $ jps



### +) Command
    ## default
    > cat : concatenate
    > >> : append
    > ln [-s --symbolic : 심볼릭 링크 생성] [-f --force : 기존 대상 파일 제거]
    > chown [-R : 하위 폴더/파일에도 모두 적용] [OWNER][:[GROUP]] : 파일 소유자/그룹 변경
    > tar [-x : 파일 추출] [-v : 처리과정 표시] [-f : 대상 지정]
    ## user
    > addgroup : 사용자 그룹추가
    > adduser [-ingroup : 특정 그룹 지정하여 사용자 추가] : 사용자 추가 
    > su - [username] : 사용자 전환 (su - change user ID or become superuser)
    ## ssh
    > ssh [server] : ssh 접속
    > ssh-keygen [-t : 키 타입] [-P passphrase : Provides the (old) passphrase.] : 인증키 생성/관리 
    > ssh-copy-id [-i : 암호파일] [server] [-yes] : ssh를 사용하여 원격 시스템에 로그인하는 스크립트 암호 입력 대신 암호 파일을 사용하도록 설정
