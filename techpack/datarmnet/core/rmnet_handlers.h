/* Copyright (c) 2013, 2016-2017, 2019-2020, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * RMNET Data ingress/egress handler
 *
 */

#ifndef _RMNET_HANDLERS_H_
#define _RMNET_HANDLERS_H_

#include "rmnet_config.h"

enum rmnet_packet_context {
	RMNET_NET_RX_CTX,
	RMNET_WQ_CTX,
};

void rmnet_egress_handler(struct sk_buff *skb);
void rmnet_deliver_skb(struct sk_buff *skb, struct rmnet_port *port);
void rmnet_deliver_skb_wq(struct sk_buff *skb, struct rmnet_port *port,
			  enum rmnet_packet_context ctx);
void rmnet_set_skb_proto(struct sk_buff *skb);
bool rmnet_slow_start_on(u32 hash_key);
rx_handler_result_t _rmnet_map_ingress_handler(struct sk_buff *skb,
					       struct rmnet_port *port);
rx_handler_result_t rmnet_rx_handler(struct sk_buff **pskb);

#endif /* _RMNET_HANDLERS_H_ */