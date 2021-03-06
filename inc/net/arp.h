/*
 * Copyright (c) 2015-2017, Stanford University
 *  
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *  * Redistributions of source code must retain the above copyright notice, 
 *    this list of conditions and the following disclaimer.
 * 
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 *  * Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Copyright 2013-16 Board of Trustees of Stanford University
 * Copyright 2013-16 Ecole Polytechnique Federale Lausanne (EPFL)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*
 * arp.h - Address Resolution Protocol (RFC 826, RFC 903)
 */

#pragma once

#include <net/ethernet.h>
#include <net/ip.h>

struct arp_hdr {
	uint16_t htype;
	uint16_t ptype;		/* the ETHERTYPE */
	uint8_t  hlen;
	uint8_t  plen;
	uint16_t op;

	/*
	 * Variable length fields continue as follows:
	 *    sender hw addr: hlen bytes
	 *    sender protocol addr: plen bytes
	 *    target hw addr: hlen bytes
	 *    target protocol addr: plen bytes
	 */
} __packed;

struct arp_hdr_ethip {
	struct eth_addr	sender_mac;
	struct ip_addr	sender_ip;
	struct eth_addr	target_mac;
	struct ip_addr	target_ip;
} __packed;

#define ARP_HTYPE_ETHER		1	/* ethernet */
#define ARP_HTYPE_IEEE802	6	/* token-ring */
#define ARP_HTYPE_ARCNET	7	/* arcnet */
#define ARP_HTYPE_FRELAY	16	/* frame relay */
#define ARP_HTYPE_IEEE1394	24	/* firewire */
#define ARP_HTYPE_INFINIBAND	32	/* infiniband */

enum {
	ARP_OP_REQUEST = 1,	/* request hw addr given protocol addr */
	ARP_OP_REPLY = 2,	/* response hw addr given protocol addr  */
	ARP_OP_REVREQUEST = 3,	/* request protocol addr given hw addr */
	ARP_OP_REVREPLY = 4,	/* response protocol addr given hw addr */
};

