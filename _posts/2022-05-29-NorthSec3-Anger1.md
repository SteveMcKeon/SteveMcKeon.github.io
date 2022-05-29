---
layout: post
title: Portobello 53 - Anger 1/2
subtitle: NorthSec2022 CTF Challenge
thumbnail-img: /assets/img/northsec-icon.png
tags: [NorthSec2022, ctf, Portobello 53]
---

Looking through the other interesting UDP streams from portobello53.pcapng, UDP stream 2 stood out and appeared to contain some Base64 encoded data. 

## Anger 1/2

In this stream, the data flow was between \[IPV6\]::3 and \[IPV6\]::100. Specifically, \[IPV6\]::3 was sending DNS TXT record queries, the responses of which contained the interesting data.

![DNS stream 2](../assets/img/anger1/anger1_1.png){: .mx-auto.d-block :}

Let's grab the data from the first packet to confirm it is in fact Base64 encoded...

![decoded Base64](../assets/img/anger1/anger1_2.png){: .mx-auto.d-block :}

Well that didn't take much. First flag in the Anger stream found for 1 point:  
**flag-radio-mycoverse-is-a-scam**.
