#!/bin/sh

iptables -F
iptables -t nat -F

# Redirect all HTTP to portal
iptables -t nat -A PREROUTING -i wlan0 -p tcp --dport 80 -j DNAT --to 192.168.1.1:8080

# Allow DNS
iptables -A FORWARD -p udp --dport 53 -j ACCEPT

# Block all else
iptables -A FORWARD -j DROP
