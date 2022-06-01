---
layout: post
title: Portobello 53 - Anger
subtitle: NorthSec2022 CTF Challenge Writeup
thumbnail-img: /assets/img/northsec-icon.png
tags: [NorthSec2022, ctf, Portobello 53]
---

Looking through the other interesting UDP streams from portobello53.pcapng, UDP stream 2 stood out and appeared to contain some Base64 encoded data. 

## Anger 1/2

In this stream, the data flow was between \[IPV6\]::3 and \[IPV6\]::100. Specifically, \[IPV6\]::3 was sending DNS TXT record queries, the responses of which contained the interesting data.

![DNS stream 2](/assets/img/anger/anger1_1.png){: .mx-auto.d-block :}

Let's grab the data from the first packet to confirm it is in fact Base64 encoded...

![decoded Base64](/assets/img/anger/anger1_2.png){: .mx-auto.d-block :}

Well that didn't take much. First flag in the Anger stream found for 1 point:  
**flag-radio-mycoverse-is-a-scam**.

## Anger 2/2

When we found the first flag, the initial packet's data decoded to "ID3TPE1S3RL ft KrystalTIT2Tripping on MushroomsCOMM#flag-radio-mycoverse-is-a-scamCOMM#XXXflag-radio-mycoverse-is-a-scam���D".

A quick google search results in the song "Tripping on Mushrooms - S3RL ft Krystal". 

Looking instead for the string "ID3TPE1", I discovered that ID3 is a metadata container, with TPE1 identifying the artist and TIT2 identifying the title of the song. ID3 is the *magic number* for an MP3 file with an ID3v2 container. 

The plan is therefore to extract all of the data from the DNS TXT Record responses, concatenate it together, and hopefully we can listen to a song and perhaps find some extra data embedded in some way (Steganography!).

Here's the half of the communication channel with the Base64 encoded data. 

![DNS stream 2, base64 encoded data](/assets/img/anger/anger2_1.png){: .mx-auto.d-block :}

There doesn't seem to be a quick and easy way to RegEx-fu the rest of this tunnel like we did for the previous flags, so lets level up and try something better.

Enter python and scapy. I filtered the original capture down to just the relevant packets and saved it as a new pcap for use in a script. A quick test shows the pcap was correctly parsed and the data we want is present in the *rdata* field of the DNSRR.

![Python and Scapy test](/assets/img/anger/anger2_2.png){: .mx-auto.d-block :}

Now all that's left is to grab all the data and stick it together, then write it to a file which we can then try to listen to.

```python
#!/usr/bin/env python3
from scapy.all import *
from scapy.layers.dns import DNS, DNSRR
import base64

rdata = bytes()

dns_packets = rdpcap('beats.ctf.pcapng')

for pkt in dns_packets:
    rdata = rdata + (pkt[DNSRR].rdata)[0]

mp3_bytes = base64.b64decode(rdata)

mp3_file = open("mp3_file.mp3", "wb")
mp3_file.write(mp3_bytes)
mp3_file.close()
```

Upon listening to the [mp3](/assets/files/mp3_file.mp3), which is a short 28 second clip, the song (Tripping on Mushrooms) is interrupted by someone who says "pardon the interruption but the flag is ... flag*dash*radiocashmoneymushroom247". So there's our next flag, for 2 points this time:  
**flag-radiocashmoneymushroom247**.
