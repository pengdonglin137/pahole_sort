#ifndef _BTF_ENCODER_H_
#define _BTF_ENCODER_H_ 1
/*
  SPDX-License-Identifier: GPL-2.0-only

  Copyright (C) 2019 Facebook

  Derived from ctf_encoder.h, which is:
  Copyright (C) Arnaldo Carvalho de Melo <acme@redhat.com>
 */

struct btf;
struct btf_elf;
struct cu;

struct btf_encoder {
	struct btf_elf *btfe;
};

struct btf_encoder *btf_encoder__new(struct cu *cu, struct btf *base_btf, bool skip_encoding_vars);
void btf_encoder__delete(struct btf_encoder *encoder);

int btf_encoder__encode(const char *filename);

int cu__encode_btf(struct cu *cu, struct btf *base_btf, int verbose, bool force,
		   bool skip_encoding_vars, const char *detached_btf_filename);

#endif /* _BTF_ENCODER_H_ */
