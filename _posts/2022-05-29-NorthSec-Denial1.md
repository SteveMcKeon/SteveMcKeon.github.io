---
layout: post
title: Portobello 53 - Denial 1/2
subtitle: NorthSec2022 CTF Challenge
thumbnail-img: /assets/img/northsec-icon.png
tags: [NorthSec2022, ctf]
---

# portobello53.pcap
This stream revolves around DNS tunnels - primarily identifying and decoding them. For the most part, they are pretty easy to spot. DNS requires that readable characters are used, meaning arbitrary data (i.e., high entropy URLs) stand out like a sore thumb. 
The only subset of DNS tunnels that can be tricky to spot are those that rely on very low bandwidth communication, such as sending a character at a time over a long period of time. 

After downloading and opening the pcapng in Wireshark, I started off by following the UDP streams to see if anything stood out.

UDP streams 2, 4, 8, and 9 looked to be of interest. The Denial stream is UDP stream 8.

## Denial 1/2
Upon examining the UDP stream, I could see that immediately before the string "$lag-dns-cannot-be-abused-pinky-swear.ctf" were single characters that were being sent from \[IPV6\]::beef to \[IPV6\]::100 and returned in the AAAA record.

![DNS stream 8](../assets/img/denial1_1.png){: .mx-auto.d-block :}
