# Network Traffic Analysis Script
## Description:
```
This script analyzes a network traffic capture file (pcap file) and outputs a summary of the traffic.
```
### 1. Objective

The primary objective of this network task is to analyze network traffic using Wireshark and automate specific tasks with a Bash script, generating a summary report.

### 2. Scope

1. Capture network traffic using Wireshark.
2. Develop a Bash script to analyze the captured data.
3. Extract relevant information like total packets, protocols, and top source/destination IP addresses.
4. Generate a summary report based on the analysis.
### 3. Prerequisites

1. Wireshark installed.
2. Permission to capture network traffic.
3. Basic Bash scripting knowledge.

### 4. Wireshark Capture

1. Start Wireshark and capture network traffic.
2. Save the captured data in a pcap file (e.g., your_capture_file.pcap).
## Usage

```shell
./analyze_traffic.sh <path_to_pcap_file>

## Output

The script outputs a summary of the network traffic, including:

1. Total number of packets
2. Number of HTTP and HTTPS/TLS packets
3. Top 5 source IP addresses and the number of packets for each
4. Top 5 destination IP addresses and the number of packets for each


```

## Example
```
---- Network Traffic Analysis Report -----

1. Total Packets: 10000

2. Protocols:

   - HTTP: 5000 packets

   - HTTPS/TLS: 3000 packets

3. Top 5 Source IP Addresses:

   - 192.168.1.1: 300 packets

   - 192.168.1.2: 200 packets

   - ...

4. Top 5 Destination IP Addresses:

   - 10.0.0.1: 400 packets

   - 10.0.0.2: 300 packets

   - ...

----- End of Report -----


```

## Dependencies

This script requires the `tshark` command-line network protocol analyzer. You can install it on Ubuntu with `sudo apt install tshark`.

