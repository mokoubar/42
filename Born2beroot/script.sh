#!/bin/bash

#Architecture
ARCH=$(uname -a)

#CPU
CPU=$(grep 'physical id' /proc/cpuinfo | uniq | wc -l)
VCPU=$(grep processor /proc/cpuinfo | wc -l)
CPULOAD=$(top -bn 2 | grep '%Cpu' | tail -n1 | cut -c 9- | xargs | awk '{printf("%.1f%%\n", $1 + $3)}')

#Memory Usage
MEMUSED=$(free --mega | awk 'NR==2 {print $3}')
MEMTOTAL=$(free --mega | awk  'NR==2 {print $2}')
USAGE_RATE=$(free --kilo | grep Mem | awk '{printf("%.2f%%"), $3 / $2 * 100}')

#Disk Usage
DISKUSED=$(df -h --total | grep total | awk '{printf("%d"), $3 * 1000}')
DISKTOTAL=$(df -h --total | grep total | awk '{print $2}')
DISKUSAGE_RATE=$(df -h --total | grep total | awk '{print $5}')

#Last boot
LASTBOOT=$(uptime -s | cut -d':' -f1,2)

#LVM Use
LVMUSE=$(if lsblk | grep -q lvm;then echo "yes"; else echo "no"; fi)

#Connections TCP
TCPCONNECTIONS=$(ss -t -a | grep ESTAB | wc -l)

#User log
USERLOG=$(who | wc -l)

#Network
IPV4=$(hostname -I)
MAC=$(ip link show | awk '$1 == "link/ether" {print $2}')

#Sudo
SUDOCOMMANDS=$(grep COMMAND /var/log/sudo/sudo.log | wc -l)

wall "  #Archeticture: $ARCH
        #CPU physical : $CPU
        #vCPU : $VCPU
        #Memory Usage: $MEMUSED/${MEMTOTAL}MB ($USAGE_RATE)
        #Disk Usage: $DISKUSED/${DISKTOTAL}b ($DISKUSAGE_RATE)
        #CPU load: $CPULOAD
        #Last boot: $LASTBOOT
        #LVM use: $LVMUSE
        #Connections TCP : $TCPCONNECTIONS ESTABLISHED
        #User log: $USERLOG
        #Network: IP $IPV4 ($MAC)
        #Sudo : $SUDOCOMMANDS cmd"
