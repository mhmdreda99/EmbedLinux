#!/bin/bash

# Bash Script to Analyze Network Traffic

# Input: Path to the Wireshark pcap file
pcap_file=$1

# Function to extract information from the pcap file
analyze_traffic() {
    # Use tshark to analyze the pcap file
    total_packets=$(tshark -r "$pcap_file" -T fields -e frame.number | wc -l)
    http_packets=$(tshark -r "$pcap_file" -Y "http" -T fields -e frame.number | wc -l)
    https_packets=$(tshark -r "$pcap_file" -Y "tls" -T fields -e frame.number | wc -l)
    # Get top 5 source IP addresses
    top_source_ips=$(tshark -r "$pcap_file" -T fields -e ip.src | sort | uniq -c | sort -nr | head -n 5 | awk '{print "   - " $2 ": " $1 " packets"}')

    # Get top 5 destination IP addresses
    top_dest_ips=$(tshark -r "$pcap_file" -T fields -e ip.dst | sort | uniq -c | sort -nr | head -n 5 | awk '{print "   - " $2 ": " $1 " packets"}')

    # Output analysis summary
    echo "----- Network Traffic Analysis Report -----"
    echo "1. Total Packets: $total_packets"
    echo "2. Protocols:"
    echo "   - HTTP: $http_packets packets"
    echo "   - HTTPS/TLS: $https_packets packets"
    echo ""
    echo "3. Top 5 Source IP Addresses:"
    echo "$top_source_ips"
    echo ""
    echo "4. Top 5 Destination IP Addresses:"
    echo "$top_dest_ips"
    echo "----- End of Report -----"
}
# Run the analysis function
analyze_traffic
