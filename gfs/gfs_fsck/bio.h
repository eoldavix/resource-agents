/******************************************************************************
*******************************************************************************
**
**  Copyright (C) Sistina Software, Inc.  1997-2003  All rights reserved.
**  Copyright (C) 2004-2005 Red Hat, Inc.  All rights reserved.
**
**  This copyrighted material is made available to anyone wishing to use,
**  modify, copy, or redistribute it subject to the terms and conditions
**  of the GNU General Public License v.2.
**
*******************************************************************************
******************************************************************************/

#ifndef __BIO_H
#define __BIO_H

#include "osi_user.h"
#include "fsck_incore.h"
/* buf_write flags */
#define BW_WAIT 1


#define BH_DATA(bh) ((char *)(bh)->b_data)
#define BH_BLKNO(bh) ((uint64)(bh)->b_blocknr)
#define BH_SIZE(bh) ((uint32)(bh)->b_size)
#define BH_STATE(bh) ((uint32)(bh)->b_state)

int get_buf(struct fsck_sb *sdp, uint64 blkno, osi_buf_t **bhp);
void relse_buf(struct fsck_sb *sdp, osi_buf_t *bh);
int read_buf(struct fsck_sb *sdp, osi_buf_t *bh, int flags);
int write_buf(struct fsck_sb *sdp, osi_buf_t *bh, int flags);
int get_and_read_buf(struct fsck_sb *sdp, uint64 blkno, osi_buf_t **bhp, int flags);

#endif  /*  __BIO_H  */

