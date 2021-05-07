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

    $ sudo gedit /etc/profile

      // add last line
      export JAVA_HOME=/usr/local/java
      export PATH=$PATH:$JAVA_HOME/bin
      export CLASS_PATH="."
      
    $ source /etc/profile

 ### Configuration Setting
    $ sudo gedit /etc/sysctl.conf
      // add last line
      #disable ipv6
      net.ipv6.conf.all.disable_ipv6 = 1
      net.ipv6.conf.default.disable_ipv6 = 1
      net.ipv6.conf.lo.disable_ipv6 = 1
    $ sudo reboot
    
