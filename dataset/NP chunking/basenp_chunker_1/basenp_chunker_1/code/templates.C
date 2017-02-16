// BaseNP Chunker, v. 1
// Copyright (C) 1995 University of Pennsylvania
// See file README_chunker for further information.

#include "defns.H"
#include "templ_enum.H"
#include "types.H"
#include "extern.H"
#include "rules.H"

void init_templ_table() {
  templ_table.add_string("T0W0");
  templ_table.add_string("T0W1");
  templ_table.add_string("T0W_1");
  templ_table.add_string("T0W1W2");
  templ_table.add_string("T0W_2W_1");
  templ_table.add_string("T0W0W1");
  templ_table.add_string("T0W_1W0");
  templ_table.add_string("T0W_1W1");
  templ_table.add_string("T0W123");
  templ_table.add_string("T0W_3_2_1");
  templ_table.add_string("T0P0");
  templ_table.add_string("T0P1");
  templ_table.add_string("T0P_1");
  templ_table.add_string("T0P1P2");
  templ_table.add_string("T0P_2P_1");
  templ_table.add_string("T0P0P1");
  templ_table.add_string("T0P_1P0");
  templ_table.add_string("T0P_1P1");
  templ_table.add_string("T0P123");
  templ_table.add_string("T0P_3_2_1");

  templ_table.add_string("T_1T0W0");
  templ_table.add_string("T_1T0W1");
  templ_table.add_string("T_1T0W_1");
  templ_table.add_string("T_1T0W1W2");
  templ_table.add_string("T_1T0W_2W_1");
  templ_table.add_string("T_1T0W0W1");
  templ_table.add_string("T_1T0W_1W0");
  templ_table.add_string("T_1T0W_1W1");
  templ_table.add_string("T_1T0W123");
  templ_table.add_string("T_1T0W_3_2_1");
  templ_table.add_string("T_1T0P0");
  templ_table.add_string("T_1T0P1");
  templ_table.add_string("T_1T0P_1");
  templ_table.add_string("T_1T0P1P2");
  templ_table.add_string("T_1T0P_2P_1");
  templ_table.add_string("T_1T0P0P1");
  templ_table.add_string("T_1T0P_1P0");
  templ_table.add_string("T_1T0P_1P1");
  templ_table.add_string("T_1T0P123");
  templ_table.add_string("T_1T0P_3_2_1");

  templ_table.add_string("T0T1W0");
  templ_table.add_string("T0T1W1");
  templ_table.add_string("T0T1W_1");
  templ_table.add_string("T0T1W1W2");
  templ_table.add_string("T0T1W_2W_1");
  templ_table.add_string("T0T1W0W1");
  templ_table.add_string("T0T1W_1W0");
  templ_table.add_string("T0T1W_1W1");
  templ_table.add_string("T0T1W123");
  templ_table.add_string("T0T1W_3_2_1");
  templ_table.add_string("T0T1P0");
  templ_table.add_string("T0T1P1");
  templ_table.add_string("T0T1P_1");
  templ_table.add_string("T0T1P1P2");
  templ_table.add_string("T0T1P_2P_1");
  templ_table.add_string("T0T1P0P1");
  templ_table.add_string("T0T1P_1P0");
  templ_table.add_string("T0T1P_1P1");
  templ_table.add_string("T0T1P123");
  templ_table.add_string("T0T1P_3_2_1");

  templ_table.add_string("T_2T_1W0");
  templ_table.add_string("T_2T_1W1");
  templ_table.add_string("T_2T_1W_1");
  templ_table.add_string("T_2T_1W1W2");
  templ_table.add_string("T_2T_1W_2W_1");
  templ_table.add_string("T_2T_1W0W1");
  templ_table.add_string("T_2T_1W_1W0");
  templ_table.add_string("T_2T_1W_1W1");
  templ_table.add_string("T_2T_1W123");
  templ_table.add_string("T_2T_1W_3_2_1");
  templ_table.add_string("T_2T_1P0");
  templ_table.add_string("T_2T_1P1");
  templ_table.add_string("T_2T_1P_1");
  templ_table.add_string("T_2T_1P1P2");
  templ_table.add_string("T_2T_1P_2P_1");
  templ_table.add_string("T_2T_1P0P1");
  templ_table.add_string("T_2T_1P_1P0");
  templ_table.add_string("T_2T_1P_1P1");
  templ_table.add_string("T_2T_1P123");
  templ_table.add_string("T_2T_1P_3_2_1");

  templ_table.add_string("T1T2W0");
  templ_table.add_string("T1T2W1");
  templ_table.add_string("T1T2W_1");
  templ_table.add_string("T1T2W1W2");
  templ_table.add_string("T1T2W_2W_1");
  templ_table.add_string("T1T2W0W1");
  templ_table.add_string("T1T2W_1W0");
  templ_table.add_string("T1T2W_1W1");
  templ_table.add_string("T1T2W123");
  templ_table.add_string("T1T2W_3_2_1");
  templ_table.add_string("T1T2P0");
  templ_table.add_string("T1T2P1");
  templ_table.add_string("T1T2P_1");
  templ_table.add_string("T1T2P1P2");
  templ_table.add_string("T1T2P_2P_1");
  templ_table.add_string("T1T2P0P1");
  templ_table.add_string("T1T2P_1P0");
  templ_table.add_string("T1T2P_1P1");
  templ_table.add_string("T1T2P123");
  templ_table.add_string("T1T2P_3_2_1");

  template_count = templ_table.count();
}

void init_templ_arg_type_array() {
  int templ;
  templ = templ_table.look_up("T0W0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = WORD;
  templ = templ_table.look_up("T0W1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = WORD;
  templ = templ_table.look_up("T0W_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = WORD;
  templ = templ_table.look_up("T0W1W2");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = WORD;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T0W_2W_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = WORD;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T0W0W1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = WORD;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T0W_1W0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = WORD;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T0W_1W1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = WORD;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T0W123");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = WORD;
  templ = templ_table.look_up("T0W_3_2_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = WORD;
  templ = templ_table.look_up("T0P0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = POS_TAG;
  templ = templ_table.look_up("T0P1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = POS_TAG;
  templ = templ_table.look_up("T0P_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = POS_TAG;
  templ = templ_table.look_up("T0P1P2");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = POS_TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T0P_2P_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = POS_TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T0P0P1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = POS_TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T0P_1P0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = POS_TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T0P_1P1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = POS_TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T0P123");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = POS_TAG;
  templ = templ_table.look_up("T0P_3_2_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = POS_TAG;

  templ = templ_table.look_up("T_1T0W0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T_1T0W1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T_1T0W_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T_1T0W1W2");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T_1T0W_2W_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T_1T0W0W1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T_1T0W_1W0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T_1T0W_1W1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T_1T0W123");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T_1T0W_3_2_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T_1T0P0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T_1T0P1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T_1T0P_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T_1T0P1P2");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T_1T0P_2P_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T_1T0P0P1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T_1T0P_1P0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T_1T0P_1P1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T_1T0P123");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T_1T0P_3_2_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;

  templ = templ_table.look_up("T0T1W0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T0T1W1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T0T1W_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T0T1W1W2");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T0T1W_2W_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T0T1W0W1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T0T1W_1W0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T0T1W_1W1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T0T1W123");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T0T1W_3_2_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T0T1P0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T0T1P1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T0T1P_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T0T1P1P2");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T0T1P_2P_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T0T1P0P1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T0T1P_1P0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T0T1P_1P1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T0T1P123");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T0T1P_3_2_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;

  templ = templ_table.look_up("T_2T_1W0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T_2T_1W1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T_2T_1W_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T_2T_1W1W2");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T_2T_1W_2W_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T_2T_1W0W1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T_2T_1W_1W0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T_2T_1W_1W1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T_2T_1W123");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T_2T_1W_3_2_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T_2T_1P0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T_2T_1P1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T_2T_1P_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T_2T_1P1P2");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T_2T_1P_2P_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T_2T_1P0P1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T_2T_1P_1P0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T_2T_1P_1P1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T_2T_1P123");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T_2T_1P_3_2_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;

  templ = templ_table.look_up("T1T2W0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T1T2W1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T1T2W_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T1T2W1W2");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T1T2W_2W_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T1T2W0W1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T1T2W_1W0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T1T2W_1W1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ_arg_type_array[templ][3] = WORD;
  templ = templ_table.look_up("T1T2W123");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T1T2W_3_2_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = WORD;
  templ = templ_table.look_up("T1T2P0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T1T2P1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T1T2P_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T1T2P1P2");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T1T2P_2P_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T1T2P0P1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T1T2P_1P0");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T1T2P_1P1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ_arg_type_array[templ][3] = POS_TAG;
  templ = templ_table.look_up("T1T2P123");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;
  templ = templ_table.look_up("T1T2P_3_2_1");
  templ_arg_type_array[templ][0] = TAG;
  templ_arg_type_array[templ][1] = TAG;
  templ_arg_type_array[templ][2] = POS_TAG;

}



int templ_arg_count(templ_type templ) {
  switch (templ) {
  case NO_TEMPL:
    printf("ERROR! Asking templ_arg_count of NO_TEMPL template.");
    DEBUG_ASSERT(0);
    break;
  case T0W0:
  case T0W1:
  case T0W_1:
    return(2);
  case T0W1W2:
  case T0W_2W_1:
  case T0W0W1:
  case T0W_1W0:
  case T0W_1W1:
    return(3);
  case T0W123:
  case T0W_3_2_1:
  case T0P0:
  case T0P1:
  case T0P_1:
    return(2);
  case T0P1P2:
  case T0P_2P_1:
  case T0P0P1:
  case T0P_1P0:
  case T0P_1P1:
    return(3);
  case T0P123:
  case T0P_3_2_1:
    return(2);

  case T_1T0W0:
  case T_1T0W1:
  case T_1T0W_1:
    return(3);
  case T_1T0W1W2:
  case T_1T0W_2W_1:
  case T_1T0W0W1:
  case T_1T0W_1W0:
  case T_1T0W_1W1:
    return(4);
  case T_1T0W123:
  case T_1T0W_3_2_1:
  case T_1T0P0:
  case T_1T0P1:
  case T_1T0P_1:
    return(3);
  case T_1T0P1P2:
  case T_1T0P_2P_1:
  case T_1T0P0P1:
  case T_1T0P_1P0:
  case T_1T0P_1P1:
    return(4);
  case T_1T0P123:
  case T_1T0P_3_2_1:
    return(3);

  case T0T1W0:
  case T0T1W1:
  case T0T1W_1:
    return(3);
  case T0T1W1W2:
  case T0T1W_2W_1:
  case T0T1W0W1:
  case T0T1W_1W0:
  case T0T1W_1W1:
    return(4);
  case T0T1W123:
  case T0T1W_3_2_1:
  case T0T1P0:
  case T0T1P1:
  case T0T1P_1:
    return(3);
  case T0T1P1P2:
  case T0T1P_2P_1:
  case T0T1P0P1:
  case T0T1P_1P0:
  case T0T1P_1P1:
    return(4);
  case T0T1P123:
  case T0T1P_3_2_1:
    return(3);

  case T_2T_1W0:
  case T_2T_1W1:
  case T_2T_1W_1:
    return(3);
  case T_2T_1W1W2:
  case T_2T_1W_2W_1:
  case T_2T_1W0W1:
  case T_2T_1W_1W0:
  case T_2T_1W_1W1:
    return(4);
  case T_2T_1W123:
  case T_2T_1W_3_2_1:
  case T_2T_1P0:
  case T_2T_1P1:
  case T_2T_1P_1:
    return(3);
  case T_2T_1P1P2:
  case T_2T_1P_2P_1:
  case T_2T_1P0P1:
  case T_2T_1P_1P0:
  case T_2T_1P_1P1:
    return(4);
  case T_2T_1P123:
  case T_2T_1P_3_2_1:
    return(3);

  case T1T2W0:
  case T1T2W1:
  case T1T2W_1:
    return(3);
  case T1T2W1W2:
  case T1T2W_2W_1:
  case T1T2W0W1:
  case T1T2W_1W0:
  case T1T2W_1W1:
    return(4);
  case T1T2W123:
  case T1T2W_3_2_1:
  case T1T2P0:
  case T1T2P1:
  case T1T2P_1:
    return(3);
  case T1T2P1P2:
  case T1T2P_2P_1:
  case T1T2P0P1:
  case T1T2P_1P0:
  case T1T2P_1P1:
    return(4);
  case T1T2P123:
  case T1T2P_3_2_1:
    return(3);

  }
  printf("ERROR!  Fell through case in templ_arg_count");
  DEBUG_ASSERT(0);
  return(-1);
}

int templ_alt_count(templ_type templ) {
  switch (templ) {
  case NO_TEMPL:
    printf("ERROR! Asking templ_alt_count of NO_TEMPL template.");
    DEBUG_ASSERT(0);
    break;
  case T0W0:
  case T0W1:
  case T0W_1:
  case T0W1W2:
  case T0W_2W_1:
  case T0W0W1:
  case T0W_1W0:
  case T0W_1W1:
    return(1);
  case T0W123:
  case T0W_3_2_1:
    return(3);
  case T0P0:
  case T0P1:
  case T0P_1:
  case T0P1P2:
  case T0P_2P_1:
  case T0P0P1:
  case T0P_1P0:
  case T0P_1P1:
    return(1);
  case T0P123:
  case T0P_3_2_1:
    return(3);

  case T_1T0W0:
  case T_1T0W1:
  case T_1T0W_1:
  case T_1T0W1W2:
  case T_1T0W_2W_1:
  case T_1T0W0W1:
  case T_1T0W_1W0:
  case T_1T0W_1W1:
    return(1);
  case T_1T0W123:
  case T_1T0W_3_2_1:
    return(3);
  case T_1T0P0:
  case T_1T0P1:
  case T_1T0P_1:
  case T_1T0P1P2:
  case T_1T0P_2P_1:
  case T_1T0P0P1:
  case T_1T0P_1P0:
  case T_1T0P_1P1:
    return(1);
  case T_1T0P123:
  case T_1T0P_3_2_1:
    return(3);

  case T0T1W0:
  case T0T1W1:
  case T0T1W_1:
  case T0T1W1W2:
  case T0T1W_2W_1:
  case T0T1W0W1:
  case T0T1W_1W0:
  case T0T1W_1W1:
    return(1);
  case T0T1W123:
  case T0T1W_3_2_1:
    return(3);
  case T0T1P0:
  case T0T1P1:
  case T0T1P_1:
  case T0T1P1P2:
  case T0T1P_2P_1:
  case T0T1P0P1:
  case T0T1P_1P0:
  case T0T1P_1P1:
    return(1);
  case T0T1P123:
  case T0T1P_3_2_1:
    return(3);

  case T_2T_1W0:
  case T_2T_1W1:
  case T_2T_1W_1:
  case T_2T_1W1W2:
  case T_2T_1W_2W_1:
  case T_2T_1W0W1:
  case T_2T_1W_1W0:
  case T_2T_1W_1W1:
    return(1);
  case T_2T_1W123:
  case T_2T_1W_3_2_1:
    return(3);
  case T_2T_1P0:
  case T_2T_1P1:
  case T_2T_1P_1:
  case T_2T_1P1P2:
  case T_2T_1P_2P_1:
  case T_2T_1P0P1:
  case T_2T_1P_1P0:
  case T_2T_1P_1P1:
    return(1);
  case T_2T_1P123:
  case T_2T_1P_3_2_1:
    return(3);

  case T1T2W0:
  case T1T2W1:
  case T1T2W_1:
  case T1T2W1W2:
  case T1T2W_2W_1:
  case T1T2W0W1:
  case T1T2W_1W0:
  case T1T2W_1W1:
    return(1);
  case T1T2W123:
  case T1T2W_3_2_1:
    return(3);
  case T1T2P0:
  case T1T2P1:
  case T1T2P_1:
  case T1T2P1P2:
  case T1T2P_2P_1:
  case T1T2P0P1:
  case T1T2P_1P0:
  case T1T2P_1P1:
    return(1);
  case T1T2P123:
  case T1T2P_3_2_1:
    return(3);

  }
  printf("ERROR!  Fell through case in templ_alt_count");
  DEBUG_ASSERT(0);
  return(-1);
}

void templ_args(templ_type templ, int word_num, templ_arg_type args[max_rule_args], int alt) {
  switch (templ) {
  case NO_TEMPL:
    printf("ERROR! Instantiating args of NO_TEMPL template.");
    DEBUG_ASSERT(0);
    break;
  case T0W0:
    args[0] = word_tag(word_num, 0);
    args[1] = word_lex_tag(word_num, 0);
    break;
  case T0W1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_lex_tag(word_num, 1);
    break;
  case T0W_1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_lex_tag(word_num, -1);
    break;
  case T0W1W2:
    args[0] = word_tag(word_num, 0);
    args[1] = word_lex_tag(word_num, 1);
    args[2] = word_lex_tag(word_num, 2);
    break;
  case T0W_2W_1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_lex_tag(word_num, -2);
    args[2] = word_lex_tag(word_num, -1);
    break;
  case T0W0W1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_lex_tag(word_num, 0);
    args[2] = word_lex_tag(word_num, 1);
    break;
  case T0W_1W0:
    args[0] = word_tag(word_num, 0);
    args[1] = word_lex_tag(word_num, -1);
    args[2] = word_lex_tag(word_num, 0);
    break;
  case T0W_1W1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_lex_tag(word_num, -1);
    args[2] = word_lex_tag(word_num, 1);
    break;
  case T0W123:
    args[0] = word_tag(word_num, 0);
    switch (alt) {
    case 0:
      args[1] = word_lex_tag(word_num, 1);
      break;
    case 1:
      args[1] = word_lex_tag(word_num, 2);
      break;
    case 2:
      args[1] = word_lex_tag(word_num, 3);
      break;
    }
    break;
  case T0W_3_2_1:
    args[0] = word_tag(word_num, 0);
    switch (alt) {
    case 0:
      args[1] = word_lex_tag(word_num, -3);
      break;
    case 1:
      args[1] = word_lex_tag(word_num, -2);
      break;
    case 2:
      args[1] = word_lex_tag(word_num, -1);
      break;
    }
    break;
  case T0P0:
    args[0] = word_tag(word_num, 0);
    args[1] = word_pos_tag(word_num, 0);
    break;
  case T0P1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_pos_tag(word_num, 1);
    break;
  case T0P_1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_pos_tag(word_num, -1);
    break;
  case T0P1P2:
    args[0] = word_tag(word_num, 0);
    args[1] = word_pos_tag(word_num, 1);
    args[2] = word_pos_tag(word_num, 2);
    break;
  case T0P_2P_1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_pos_tag(word_num, -2);
    args[2] = word_pos_tag(word_num, -1);
    break;
  case T0P0P1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_pos_tag(word_num, 0);
    args[2] = word_pos_tag(word_num, 1);
    break;
  case T0P_1P0:
    args[0] = word_tag(word_num, 0);
    args[1] = word_pos_tag(word_num, -1);
    args[2] = word_pos_tag(word_num, 0);
    break;
  case T0P_1P1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_pos_tag(word_num, -1);
    args[2] = word_pos_tag(word_num, 1);
    break;
  case T0P123:
    args[0] = word_tag(word_num, 0);
    switch (alt) {
    case 0:
      args[1] = word_pos_tag(word_num, 1);
      break;
    case 1:
      args[1] = word_pos_tag(word_num, 2);
      break;
    case 2:
      args[1] = word_pos_tag(word_num, 3);
      break;
    }
    break;
  case T0P_3_2_1:
    args[0] = word_tag(word_num, 0);
    switch (alt) {
    case 0:
      args[1] = word_pos_tag(word_num, -3);
      break;
    case 1:
      args[1] = word_pos_tag(word_num, -2);
      break;
    case 2:
      args[1] = word_pos_tag(word_num, -1);
      break;
    }
    break;

  case T_1T0W0:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    args[2] = word_lex_tag(word_num, 0);
    break;
  case T_1T0W1:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    args[2] = word_lex_tag(word_num, 1);
    break;
  case T_1T0W_1:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    args[2] = word_lex_tag(word_num, -1);
    break;
  case T_1T0W1W2:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    args[2] = word_lex_tag(word_num, 1);
    args[3] = word_lex_tag(word_num, 2);
    break;
  case T_1T0W_2W_1:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    args[2] = word_lex_tag(word_num, -2);
    args[3] = word_lex_tag(word_num, -1);
    break;
  case T_1T0W0W1:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    args[2] = word_lex_tag(word_num, 0);
    args[3] = word_lex_tag(word_num, 1);
    break;
  case T_1T0W_1W0:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    args[2] = word_lex_tag(word_num, -1);
    args[3] = word_lex_tag(word_num, 0);
    break;
  case T_1T0W_1W1:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    args[2] = word_lex_tag(word_num, -1);
    args[3] = word_lex_tag(word_num, 1);
    break;
  case T_1T0W123:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    switch (alt) {
    case 0:
      args[2] = word_lex_tag(word_num, 1);
      break;
    case 1:
      args[2] = word_lex_tag(word_num, 2);
      break;
    case 2:
      args[2] = word_lex_tag(word_num, 3);
      break;
    }
    break;
  case T_1T0W_3_2_1:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    switch (alt) {
    case 0:
      args[2] = word_lex_tag(word_num, -3);
      break;
    case 1:
      args[2] = word_lex_tag(word_num, -2);
      break;
    case 2:
      args[2] = word_lex_tag(word_num, -1);
      break;
    }
    break;
  case T_1T0P0:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    args[2] = word_pos_tag(word_num, 0);
    break;
  case T_1T0P1:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    args[2] = word_pos_tag(word_num, 1);
    break;
  case T_1T0P_1:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    args[2] = word_pos_tag(word_num, -1);
    break;
  case T_1T0P1P2:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    args[2] = word_pos_tag(word_num, 1);
    args[3] = word_pos_tag(word_num, 2);
    break;
  case T_1T0P_2P_1:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    args[2] = word_pos_tag(word_num, -2);
    args[3] = word_pos_tag(word_num, -1);
    break;
  case T_1T0P0P1:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    args[2] = word_pos_tag(word_num, 0);
    args[3] = word_pos_tag(word_num, 1);
    break;
  case T_1T0P_1P0:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    args[2] = word_pos_tag(word_num, -1);
    args[3] = word_pos_tag(word_num, 0);
    break;
  case T_1T0P_1P1:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    args[2] = word_pos_tag(word_num, -1);
    args[3] = word_pos_tag(word_num, 1);
    break;
  case T_1T0P123:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    switch (alt) {
    case 0:
      args[2] = word_pos_tag(word_num, 1);
      break;
    case 1:
      args[2] = word_pos_tag(word_num, 2);
      break;
    case 2:
      args[2] = word_pos_tag(word_num, 3);
      break;
    }
    break;
  case T_1T0P_3_2_1:
    args[0] = word_tag(word_num, -1);
    args[1] = word_tag(word_num, 0);
    switch (alt) {
    case 0:
      args[2] = word_pos_tag(word_num, -3);
      break;
    case 1:
      args[2] = word_pos_tag(word_num, -2);
      break;
    case 2:
      args[2] = word_pos_tag(word_num, -1);
      break;
    }
    break;

  case T0T1W0:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    args[2] = word_lex_tag(word_num, 0);
    break;
  case T0T1W1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    args[2] = word_lex_tag(word_num, 1);
    break;
  case T0T1W_1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    args[2] = word_lex_tag(word_num, -1);
    break;
  case T0T1W1W2:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    args[2] = word_lex_tag(word_num, 1);
    args[3] = word_lex_tag(word_num, 2);
    break;
  case T0T1W_2W_1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    args[2] = word_lex_tag(word_num, -2);
    args[3] = word_lex_tag(word_num, -1);
    break;
  case T0T1W0W1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    args[2] = word_lex_tag(word_num, 0);
    args[3] = word_lex_tag(word_num, 1);
    break;
  case T0T1W_1W0:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    args[2] = word_lex_tag(word_num, -1);
    args[3] = word_lex_tag(word_num, 0);
    break;
  case T0T1W_1W1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    args[2] = word_lex_tag(word_num, -1);
    args[3] = word_lex_tag(word_num, 1);
    break;
  case T0T1W123:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    switch (alt) {
    case 0:
      args[2] = word_lex_tag(word_num, 1);
      break;
    case 1:
      args[2] = word_lex_tag(word_num, 2);
      break;
    case 2:
      args[2] = word_lex_tag(word_num, 3);
      break;
    }
    break;
  case T0T1W_3_2_1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    switch (alt) {
    case 0:
      args[2] = word_lex_tag(word_num, -3);
      break;
    case 1:
      args[2] = word_lex_tag(word_num, -2);
      break;
    case 2:
      args[2] = word_lex_tag(word_num, -1);
      break;
    }
    break;
  case T0T1P0:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    args[2] = word_pos_tag(word_num, 0);
    break;
  case T0T1P1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    args[2] = word_pos_tag(word_num, 1);
    break;
  case T0T1P_1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    args[2] = word_pos_tag(word_num, -1);
    break;
  case T0T1P1P2:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    args[2] = word_pos_tag(word_num, 1);
    args[3] = word_pos_tag(word_num, 2);
    break;
  case T0T1P_2P_1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    args[2] = word_pos_tag(word_num, -2);
    args[3] = word_pos_tag(word_num, -1);
    break;
  case T0T1P0P1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    args[2] = word_pos_tag(word_num, 0);
    args[3] = word_pos_tag(word_num, 1);
    break;
  case T0T1P_1P0:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    args[2] = word_pos_tag(word_num, -1);
    args[3] = word_pos_tag(word_num, 0);
    break;
  case T0T1P_1P1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    args[2] = word_pos_tag(word_num, -1);
    args[3] = word_pos_tag(word_num, 1);
    break;
  case T0T1P123:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    switch (alt) {
    case 0:
      args[2] = word_pos_tag(word_num, 1);
      break;
    case 1:
      args[2] = word_pos_tag(word_num, 2);
      break;
    case 2:
      args[2] = word_pos_tag(word_num, 3);
      break;
    }
    break;
  case T0T1P_3_2_1:
    args[0] = word_tag(word_num, 0);
    args[1] = word_tag(word_num, 1);
    switch (alt) {
    case 0:
      args[2] = word_pos_tag(word_num, -3);
      break;
    case 1:
      args[2] = word_pos_tag(word_num, -2);
      break;
    case 2:
      args[2] = word_pos_tag(word_num, -1);
      break;
    }
    break;

  case T_2T_1W0:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    args[2] = word_lex_tag(word_num, 0);
    break;
  case T_2T_1W1:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    args[2] = word_lex_tag(word_num, 1);
    break;
  case T_2T_1W_1:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    args[2] = word_lex_tag(word_num, -1);
    break;
  case T_2T_1W1W2:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    args[2] = word_lex_tag(word_num, 1);
    args[3] = word_lex_tag(word_num, 2);
    break;
  case T_2T_1W_2W_1:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    args[2] = word_lex_tag(word_num, -2);
    args[3] = word_lex_tag(word_num, -1);
    break;
  case T_2T_1W0W1:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    args[2] = word_lex_tag(word_num, 0);
    args[3] = word_lex_tag(word_num, 1);
    break;
  case T_2T_1W_1W0:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    args[2] = word_lex_tag(word_num, -1);
    args[3] = word_lex_tag(word_num, 0);
    break;
  case T_2T_1W_1W1:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    args[2] = word_lex_tag(word_num, -1);
    args[3] = word_lex_tag(word_num, 1);
    break;
  case T_2T_1W123:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    switch (alt) {
    case 0:
      args[2] = word_lex_tag(word_num, 1);
      break;
    case 1:
      args[2] = word_lex_tag(word_num, 2);
      break;
    case 2:
      args[2] = word_lex_tag(word_num, 3);
      break;
    }
    break;
  case T_2T_1W_3_2_1:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    switch (alt) {
    case 0:
      args[2] = word_lex_tag(word_num, -3);
      break;
    case 1:
      args[2] = word_lex_tag(word_num, -2);
      break;
    case 2:
      args[2] = word_lex_tag(word_num, -1);
      break;
    }
    break;
  case T_2T_1P0:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    args[2] = word_pos_tag(word_num, 0);
    break;
  case T_2T_1P1:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    args[2] = word_pos_tag(word_num, 1);
    break;
  case T_2T_1P_1:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    args[2] = word_pos_tag(word_num, -1);
    break;
  case T_2T_1P1P2:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    args[2] = word_pos_tag(word_num, 1);
    args[3] = word_pos_tag(word_num, 2);
    break;
  case T_2T_1P_2P_1:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    args[2] = word_pos_tag(word_num, -2);
    args[3] = word_pos_tag(word_num, -1);
    break;
  case T_2T_1P0P1:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    args[2] = word_pos_tag(word_num, 0);
    args[3] = word_pos_tag(word_num, 1);
    break;
  case T_2T_1P_1P0:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    args[2] = word_pos_tag(word_num, -1);
    args[3] = word_pos_tag(word_num, 0);
    break;
  case T_2T_1P_1P1:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    args[2] = word_pos_tag(word_num, -1);
    args[3] = word_pos_tag(word_num, 1);
    break;
  case T_2T_1P123:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    switch (alt) {
    case 0:
      args[2] = word_pos_tag(word_num, 1);
      break;
    case 1:
      args[2] = word_pos_tag(word_num, 2);
      break;
    case 2:
      args[2] = word_pos_tag(word_num, 3);
      break;
    }
    break;
  case T_2T_1P_3_2_1:
    args[0] = word_tag(word_num, -2);
    args[1] = word_tag(word_num, -1);
    switch (alt) {
    case 0:
      args[2] = word_pos_tag(word_num, -3);
      break;
    case 1:
      args[2] = word_pos_tag(word_num, -2);
      break;
    case 2:
      args[2] = word_pos_tag(word_num, -1);
      break;
    }
    break;

  case T1T2W0:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    args[2] = word_lex_tag(word_num, 0);
    break;
  case T1T2W1:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    args[2] = word_lex_tag(word_num, 1);
    break;
  case T1T2W_1:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    args[2] = word_lex_tag(word_num, -1);
    break;
  case T1T2W1W2:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    args[2] = word_lex_tag(word_num, 1);
    args[3] = word_lex_tag(word_num, 2);
    break;
  case T1T2W_2W_1:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    args[2] = word_lex_tag(word_num, -2);
    args[3] = word_lex_tag(word_num, -1);
    break;
  case T1T2W0W1:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    args[2] = word_lex_tag(word_num, 0);
    args[3] = word_lex_tag(word_num, 1);
    break;
  case T1T2W_1W0:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    args[2] = word_lex_tag(word_num, -1);
    args[3] = word_lex_tag(word_num, 0);
    break;
  case T1T2W_1W1:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    args[2] = word_lex_tag(word_num, -1);
    args[3] = word_lex_tag(word_num, 1);
    break;
  case T1T2W123:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    switch (alt) {
    case 0:
      args[2] = word_lex_tag(word_num, 1);
      break;
    case 1:
      args[2] = word_lex_tag(word_num, 2);
      break;
    case 2:
      args[2] = word_lex_tag(word_num, 3);
      break;
    }
    break;
  case T1T2W_3_2_1:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    switch (alt) {
    case 0:
      args[2] = word_lex_tag(word_num, -3);
      break;
    case 1:
      args[2] = word_lex_tag(word_num, -2);
      break;
    case 2:
      args[2] = word_lex_tag(word_num, -1);
      break;
    }
    break;
  case T1T2P0:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    args[2] = word_pos_tag(word_num, 0);
    break;
  case T1T2P1:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    args[2] = word_pos_tag(word_num, 1);
    break;
  case T1T2P_1:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    args[2] = word_pos_tag(word_num, -1);
    break;
  case T1T2P1P2:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    args[2] = word_pos_tag(word_num, 1);
    args[3] = word_pos_tag(word_num, 2);
    break;
  case T1T2P_2P_1:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    args[2] = word_pos_tag(word_num, -2);
    args[3] = word_pos_tag(word_num, -1);
    break;
  case T1T2P0P1:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    args[2] = word_pos_tag(word_num, 0);
    args[3] = word_pos_tag(word_num, 1);
    break;
  case T1T2P_1P0:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    args[2] = word_pos_tag(word_num, -1);
    args[3] = word_pos_tag(word_num, 0);
    break;
  case T1T2P_1P1:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    args[2] = word_pos_tag(word_num, -1);
    args[3] = word_pos_tag(word_num, 1);
    break;
  case T1T2P123:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    switch (alt) {
    case 0:
      args[2] = word_pos_tag(word_num, 1);
      break;
    case 1:
      args[2] = word_pos_tag(word_num, 2);
      break;
    case 2:
      args[2] = word_pos_tag(word_num, 3);
      break;
    }
    break;
  case T1T2P_3_2_1:
    args[0] = word_tag(word_num, 1);
    args[1] = word_tag(word_num, 2);
    switch (alt) {
    case 0:
      args[2] = word_pos_tag(word_num, -3);
      break;
    case 1:
      args[2] = word_pos_tag(word_num, -2);
      break;
    case 2:
      args[2] = word_pos_tag(word_num, -1);
      break;
    }
    break;
  }
}

int match_rule(const rule_type &rule, int word_num) {
  /* here we want a fast check of whether rule applies at site */
  switch (rule.templ) {
  case NO_TEMPL:
    printf("ERROR! Instantiating args of NO_TEMPL template.");
    DEBUG_ASSERT(0);
    break;
  case T0W0:
    return(rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_lex_tag(word_num, 0));
    break;
  case T0W1:
    return(rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_lex_tag(word_num, 1));
    break;
  case T0W_1:
    return(rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_lex_tag(word_num, -1));
    break;
  case T0W1W2:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_lex_tag(word_num, 1) &&
	   rule.args[2] == word_lex_tag(word_num, 2));
    break;
  case T0W_2W_1:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_lex_tag(word_num, -2) &&
	   rule.args[2] == word_lex_tag(word_num, -1));
    break;
  case T0W0W1:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_lex_tag(word_num, 0) &&
	   rule.args[2] == word_lex_tag(word_num, 1));
    break;
  case T0W_1W0:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_lex_tag(word_num, -1) &&
	   rule.args[2] == word_lex_tag(word_num, 0));
    break;
  case T0W_1W1:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_lex_tag(word_num, -1) &&
	   rule.args[2] == word_lex_tag(word_num, 1));
    break;
  case T0W123:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   (rule.args[1] == word_lex_tag(word_num, 1) ||
	    rule.args[1] == word_lex_tag(word_num, 2) ||
	    rule.args[1] == word_lex_tag(word_num, 3)));
    break;
  case T0W_3_2_1:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   (rule.args[1] == word_lex_tag(word_num, -3) ||
	    rule.args[1] == word_lex_tag(word_num, -2) ||
	    rule.args[1] == word_lex_tag(word_num, -1)));
    break;
  case T0P0:
    return(rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_pos_tag(word_num, 0));
    break;
  case T0P1:
    return(rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_pos_tag(word_num, 1));
    break;
  case T0P_1:
    return(rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_pos_tag(word_num, -1));
    break;
  case T0P1P2:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_pos_tag(word_num, 1) &&
	   rule.args[2] == word_pos_tag(word_num, 2));
    break;
  case T0P_2P_1:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_pos_tag(word_num, -2) &&
	   rule.args[2] == word_pos_tag(word_num, -1));
    break;
  case T0P0P1:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_pos_tag(word_num, 0) &&
	   rule.args[2] == word_pos_tag(word_num, 1));
    break;
  case T0P_1P0:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_pos_tag(word_num, -1) &&
	   rule.args[2] == word_pos_tag(word_num, 0));
    break;
  case T0P_1P1:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_pos_tag(word_num, -1) &&
	   rule.args[2] == word_pos_tag(word_num, 1));
    break;
  case T0P123:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   (rule.args[1] == word_pos_tag(word_num, 1) ||
	    rule.args[1] == word_pos_tag(word_num, 2) ||
	    rule.args[1] == word_pos_tag(word_num, 3)));
    break;
  case T0P_3_2_1:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   (rule.args[1] == word_pos_tag(word_num, -3) ||
	    rule.args[1] == word_pos_tag(word_num, -2) ||
	    rule.args[1] == word_pos_tag(word_num, -1)));
    break;

  case T_1T0W0:
    return(rule.args[0] == word_tag(word_num, -1) && 
	   rule.args[1] == word_tag(word_num, 0) && 
	   rule.args[2] == word_lex_tag(word_num, 0));
    break;
  case T_1T0W1:
    return(rule.args[0] == word_tag(word_num, -1) && 
	   rule.args[1] == word_tag(word_num, 0) && 
	   rule.args[2] == word_lex_tag(word_num, 1));
    break;
  case T_1T0W_1:
    return(rule.args[0] == word_tag(word_num, -1) && 
	   rule.args[1] == word_tag(word_num, 0) && 
	   rule.args[2] == word_lex_tag(word_num, -1));
    break;
  case T_1T0W1W2:
    return(rule.args[0] == word_tag(word_num, -1) && 
	   rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_lex_tag(word_num, 1) &&
	   rule.args[3] == word_lex_tag(word_num, 2));
    break;
  case T_1T0W_2W_1:
    return(rule.args[0] == word_tag(word_num, -1) && 
	   rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_lex_tag(word_num, -2) &&
	   rule.args[3] == word_lex_tag(word_num, -1));
    break;
  case T_1T0W0W1:
    return(rule.args[0] == word_tag(word_num, -1) && 
	   rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_lex_tag(word_num, 0) &&
	   rule.args[3] == word_lex_tag(word_num, 1));
    break;
  case T_1T0W_1W0:
    return(rule.args[0] == word_tag(word_num, -1) && 
	   rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_lex_tag(word_num, -1) &&
	   rule.args[3] == word_lex_tag(word_num, 0));
    break;
  case T_1T0W_1W1:
    return(rule.args[0] == word_tag(word_num, -1) && 
	   rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_lex_tag(word_num, -1) &&
	   rule.args[3] == word_lex_tag(word_num, 1));
    break;
  case T_1T0W123:
    return(rule.args[0] == word_tag(word_num, -1) &&
	   rule.args[1] == word_tag(word_num, 0) &&
	   (rule.args[2] == word_lex_tag(word_num, 1) ||
	    rule.args[2] == word_lex_tag(word_num, 2) ||
	    rule.args[2] == word_lex_tag(word_num, 3)));
    break;
  case T_1T0W_3_2_1:
    return(rule.args[0] == word_tag(word_num, -1) &&
	   rule.args[1] == word_tag(word_num, 0) &&
	   (rule.args[2] == word_lex_tag(word_num, -3) ||
	    rule.args[2] == word_lex_tag(word_num, -2) ||
	    rule.args[2] == word_lex_tag(word_num, -1)));
    break;
  case T_1T0P0:
    return(rule.args[0] == word_tag(word_num, -1) && 
	   rule.args[1] == word_tag(word_num, 0) && 
	   rule.args[2] == word_pos_tag(word_num, 0));
    break;
  case T_1T0P1:
    return(rule.args[0] == word_tag(word_num, -1) && 
	   rule.args[1] == word_tag(word_num, 0) && 
	   rule.args[2] == word_pos_tag(word_num, 1));
    break;
  case T_1T0P_1:
    return(rule.args[0] == word_tag(word_num, -1) && 
	   rule.args[1] == word_tag(word_num, 0) && 
	   rule.args[2] == word_pos_tag(word_num, -1));
    break;
  case T_1T0P1P2:
    return(rule.args[0] == word_tag(word_num, -1) && 
	   rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_pos_tag(word_num, 1) &&
	   rule.args[3] == word_pos_tag(word_num, 2));
    break;
  case T_1T0P_2P_1:
    return(rule.args[0] == word_tag(word_num, -1) && 
	   rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_pos_tag(word_num, -2) &&
	   rule.args[3] == word_pos_tag(word_num, -1));
    break;
  case T_1T0P0P1:
    return(rule.args[0] == word_tag(word_num, -1) && 
	   rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_pos_tag(word_num, 0) &&
	   rule.args[3] == word_pos_tag(word_num, 1));
    break;
  case T_1T0P_1P0:
    return(rule.args[0] == word_tag(word_num, -1) && 
	   rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_pos_tag(word_num, -1) &&
	   rule.args[3] == word_pos_tag(word_num, 0));
    break;
  case T_1T0P_1P1:
    return(rule.args[0] == word_tag(word_num, -1) && 
	   rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_pos_tag(word_num, -1) &&
	   rule.args[3] == word_pos_tag(word_num, 1));
    break;
  case T_1T0P123:
    return(rule.args[0] == word_tag(word_num, -1) &&
	   rule.args[1] == word_tag(word_num, 0) &&
	   (rule.args[2] == word_pos_tag(word_num, 1) ||
	    rule.args[2] == word_pos_tag(word_num, 2) ||
	    rule.args[2] == word_pos_tag(word_num, 3)));
    break;
  case T_1T0P_3_2_1:
    return(rule.args[0] == word_tag(word_num, -1) &&
	   rule.args[1] == word_tag(word_num, 0) &&
	   (rule.args[2] == word_pos_tag(word_num, -3) ||
	    rule.args[2] == word_pos_tag(word_num, -2) ||
	    rule.args[2] == word_pos_tag(word_num, -1)));
    break;

  case T0T1W0:
    return(rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_lex_tag(word_num, 0));
    break;
  case T0T1W1:
    return(rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_lex_tag(word_num, 1));
    break;
  case T0T1W_1:
    return(rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_lex_tag(word_num, -1));
    break;
  case T0T1W1W2:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_lex_tag(word_num, 1) &&
	   rule.args[3] == word_lex_tag(word_num, 2));
    break;
  case T0T1W_2W_1:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_lex_tag(word_num, -2) &&
	   rule.args[3] == word_lex_tag(word_num, -1));
    break;
  case T0T1W0W1:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_lex_tag(word_num, 0) &&
	   rule.args[3] == word_lex_tag(word_num, 1));
    break;
  case T0T1W_1W0:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_lex_tag(word_num, -1) &&
	   rule.args[3] == word_lex_tag(word_num, 0));
    break;
  case T0T1W_1W1:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_lex_tag(word_num, -1) &&
	   rule.args[3] == word_lex_tag(word_num, 1));
    break;
  case T0T1W123:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_tag(word_num, 1) &&
	   (rule.args[2] == word_lex_tag(word_num, 1) ||
	    rule.args[2] == word_lex_tag(word_num, 2) ||
	    rule.args[2] == word_lex_tag(word_num, 3)));
    break;
  case T0T1W_3_2_1:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_tag(word_num, 1) &&
	   (rule.args[2] == word_lex_tag(word_num, -3) ||
	    rule.args[2] == word_lex_tag(word_num, -2) ||
	    rule.args[2] == word_lex_tag(word_num, -1)));
    break;
  case T0T1P0:
    return(rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_pos_tag(word_num, 0));
    break;
  case T0T1P1:
    return(rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_pos_tag(word_num, 1));
    break;
  case T0T1P_1:
    return(rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_pos_tag(word_num, -1));
    break;
  case T0T1P1P2:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_pos_tag(word_num, 1) &&
	   rule.args[3] == word_pos_tag(word_num, 2));
    break;
  case T0T1P_2P_1:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_pos_tag(word_num, -2) &&
	   rule.args[3] == word_pos_tag(word_num, -1));
    break;
  case T0T1P0P1:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_pos_tag(word_num, 0) &&
	   rule.args[3] == word_pos_tag(word_num, 1));
    break;
  case T0T1P_1P0:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_pos_tag(word_num, -1) &&
	   rule.args[3] == word_pos_tag(word_num, 0));
    break;
  case T0T1P_1P1:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_pos_tag(word_num, -1) &&
	   rule.args[3] == word_pos_tag(word_num, 1));
    break;
  case T0T1P123:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_tag(word_num, 1) &&
	   (rule.args[2] == word_pos_tag(word_num, 1) ||
	    rule.args[2] == word_pos_tag(word_num, 2) ||
	    rule.args[2] == word_pos_tag(word_num, 3)));
    break;
  case T0T1P_3_2_1:
    return(rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_tag(word_num, 1) &&
	   (rule.args[2] == word_pos_tag(word_num, -3) ||
	    rule.args[2] == word_pos_tag(word_num, -2) ||
	    rule.args[2] == word_pos_tag(word_num, -1)));
    break;

  case T_2T_1W0:
    return(rule.args[0] == word_tag(word_num, -2) && 
	   rule.args[1] == word_tag(word_num, -1) && 
	   rule.args[2] == word_lex_tag(word_num, 0));
    break;
  case T_2T_1W1:
    return(rule.args[0] == word_tag(word_num, -2) && 
	   rule.args[1] == word_tag(word_num, -1) && 
	   rule.args[2] == word_lex_tag(word_num, 1));
    break;
  case T_2T_1W_1:
    return(rule.args[0] == word_tag(word_num, -2) && 
	   rule.args[1] == word_tag(word_num, -1) && 
	   rule.args[2] == word_lex_tag(word_num, -1));
    break;
  case T_2T_1W1W2:
    return(rule.args[0] == word_tag(word_num, -2) && 
	   rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_lex_tag(word_num, 1) &&
	   rule.args[3] == word_lex_tag(word_num, 2));
    break;
  case T_2T_1W_2W_1:
    return(rule.args[0] == word_tag(word_num, -2) && 
	   rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_lex_tag(word_num, -2) &&
	   rule.args[3] == word_lex_tag(word_num, -1));
    break;
  case T_2T_1W0W1:
    return(rule.args[0] == word_tag(word_num, -2) && 
	   rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_lex_tag(word_num, 0) &&
	   rule.args[3] == word_lex_tag(word_num, 1));
    break;
  case T_2T_1W_1W0:
    return(rule.args[0] == word_tag(word_num, -2) && 
	   rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_lex_tag(word_num, -1) &&
	   rule.args[3] == word_lex_tag(word_num, 0));
    break;
  case T_2T_1W_1W1:
    return(rule.args[0] == word_tag(word_num, -2) && 
	   rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_lex_tag(word_num, -1) &&
	   rule.args[3] == word_lex_tag(word_num, 1));
    break;
  case T_2T_1W123:
    return(rule.args[0] == word_tag(word_num, -2) &&
	   rule.args[1] == word_tag(word_num, -1) &&
	   (rule.args[2] == word_lex_tag(word_num, 1) ||
	    rule.args[2] == word_lex_tag(word_num, 2) ||
	    rule.args[2] == word_lex_tag(word_num, 3)));
    break;
  case T_2T_1W_3_2_1:
    return(rule.args[0] == word_tag(word_num, -2) &&
	   rule.args[1] == word_tag(word_num, -1) &&
	   (rule.args[2] == word_lex_tag(word_num, -3) ||
	    rule.args[2] == word_lex_tag(word_num, -2) ||
	    rule.args[2] == word_lex_tag(word_num, -1)));
    break;
  case T_2T_1P0:
    return(rule.args[0] == word_tag(word_num, -2) && 
	   rule.args[1] == word_tag(word_num, -1) && 
	   rule.args[2] == word_pos_tag(word_num, 0));
    break;
  case T_2T_1P1:
    return(rule.args[0] == word_tag(word_num, -2) && 
	   rule.args[1] == word_tag(word_num, -1) && 
	   rule.args[2] == word_pos_tag(word_num, 1));
    break;
  case T_2T_1P_1:
    return(rule.args[0] == word_tag(word_num, -2) && 
	   rule.args[1] == word_tag(word_num, -1) && 
	   rule.args[2] == word_pos_tag(word_num, -1));
    break;
  case T_2T_1P1P2:
    return(rule.args[0] == word_tag(word_num, -2) && 
	   rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_pos_tag(word_num, 1) &&
	   rule.args[3] == word_pos_tag(word_num, 2));
    break;
  case T_2T_1P_2P_1:
    return(rule.args[0] == word_tag(word_num, -2) && 
	   rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_pos_tag(word_num, -2) &&
	   rule.args[3] == word_pos_tag(word_num, -1));
    break;
  case T_2T_1P0P1:
    return(rule.args[0] == word_tag(word_num, -2) && 
	   rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_pos_tag(word_num, 0) &&
	   rule.args[3] == word_pos_tag(word_num, 1));
    break;
  case T_2T_1P_1P0:
    return(rule.args[0] == word_tag(word_num, -2) && 
	   rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_pos_tag(word_num, -1) &&
	   rule.args[3] == word_pos_tag(word_num, 0));
    break;
  case T_2T_1P_1P1:
    return(rule.args[0] == word_tag(word_num, -2) && 
	   rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_pos_tag(word_num, -1) &&
	   rule.args[3] == word_pos_tag(word_num, 1));
    break;
  case T_2T_1P123:
    return(rule.args[0] == word_tag(word_num, -2) &&
	   rule.args[1] == word_tag(word_num, -1) &&
	   (rule.args[2] == word_pos_tag(word_num, 1) ||
	    rule.args[2] == word_pos_tag(word_num, 2) ||
	    rule.args[2] == word_pos_tag(word_num, 3)));
    break;
  case T_2T_1P_3_2_1:
    return(rule.args[0] == word_tag(word_num, -2) &&
	   rule.args[1] == word_tag(word_num, -1) &&
	   (rule.args[2] == word_pos_tag(word_num, -3) ||
	    rule.args[2] == word_pos_tag(word_num, -2) ||
	    rule.args[2] == word_pos_tag(word_num, -1)));
    break;

  case T1T2W0:
    return(rule.args[0] == word_tag(word_num, 1) && 
	   rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_lex_tag(word_num, 0));
    break;
  case T1T2W1:
    return(rule.args[0] == word_tag(word_num, 1) && 
	   rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_lex_tag(word_num, 1));
    break;
  case T1T2W_1:
    return(rule.args[0] == word_tag(word_num, 1) && 
	   rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_lex_tag(word_num, -1));
    break;
  case T1T2W1W2:
    return(rule.args[0] == word_tag(word_num, 1) &&
	   rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_lex_tag(word_num, 1) &&
	   rule.args[3] == word_lex_tag(word_num, 2));
    break;
  case T1T2W_2W_1:
    return(rule.args[0] == word_tag(word_num, 1) &&
	   rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_lex_tag(word_num, -2) &&
	   rule.args[3] == word_lex_tag(word_num, -1));
    break;
  case T1T2W0W1:
    return(rule.args[0] == word_tag(word_num, 1) &&
	   rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_lex_tag(word_num, 0) &&
	   rule.args[3] == word_lex_tag(word_num, 1));
    break;
  case T1T2W_1W0:
    return(rule.args[0] == word_tag(word_num, 1) &&
	   rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_lex_tag(word_num, -1) &&
	   rule.args[3] == word_lex_tag(word_num, 0));
    break;
  case T1T2W_1W1:
    return(rule.args[0] == word_tag(word_num, 1) &&
	   rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_lex_tag(word_num, -1) &&
	   rule.args[3] == word_lex_tag(word_num, 1));
    break;
  case T1T2W123:
    return(rule.args[0] == word_tag(word_num, 1) &&
	   rule.args[1] == word_tag(word_num, 2) &&
	   (rule.args[2] == word_lex_tag(word_num, 1) ||
	    rule.args[2] == word_lex_tag(word_num, 2) ||
	    rule.args[2] == word_lex_tag(word_num, 3)));
    break;
  case T1T2W_3_2_1:
    return(rule.args[0] == word_tag(word_num, 1) &&
	   rule.args[1] == word_tag(word_num, 2) &&
	   (rule.args[2] == word_lex_tag(word_num, -3) ||
	    rule.args[2] == word_lex_tag(word_num, -2) ||
	    rule.args[2] == word_lex_tag(word_num, -1)));
    break;
  case T1T2P0:
    return(rule.args[0] == word_tag(word_num, 1) && 
	   rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_pos_tag(word_num, 0));
    break;
  case T1T2P1:
    return(rule.args[0] == word_tag(word_num, 1) && 
	   rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_pos_tag(word_num, 1));
    break;
  case T1T2P_1:
    return(rule.args[0] == word_tag(word_num, 1) && 
	   rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_pos_tag(word_num, -1));
    break;
  case T1T2P1P2:
    return(rule.args[0] == word_tag(word_num, 1) &&
	   rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_pos_tag(word_num, 1) &&
	   rule.args[3] == word_pos_tag(word_num, 2));
    break;
  case T1T2P_2P_1:
    return(rule.args[0] == word_tag(word_num, 1) &&
	   rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_pos_tag(word_num, -2) &&
	   rule.args[3] == word_pos_tag(word_num, -1));
    break;
  case T1T2P0P1:
    return(rule.args[0] == word_tag(word_num, 1) &&
	   rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_pos_tag(word_num, 0) &&
	   rule.args[3] == word_pos_tag(word_num, 1));
    break;
  case T1T2P_1P0:
    return(rule.args[0] == word_tag(word_num, 1) &&
	   rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_pos_tag(word_num, -1) &&
	   rule.args[3] == word_pos_tag(word_num, 0));
    break;
  case T1T2P_1P1:
    return(rule.args[0] == word_tag(word_num, 1) &&
	   rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_pos_tag(word_num, -1) &&
	   rule.args[3] == word_pos_tag(word_num, 1));
    break;
  case T1T2P123:
    return(rule.args[0] == word_tag(word_num, 1) &&
	   rule.args[1] == word_tag(word_num, 2) &&
	   (rule.args[2] == word_pos_tag(word_num, 1) ||
	    rule.args[2] == word_pos_tag(word_num, 2) ||
	    rule.args[2] == word_pos_tag(word_num, 3)));
    break;
  case T1T2P_3_2_1:
    return(rule.args[0] == word_tag(word_num, 1) &&
	   rule.args[1] == word_tag(word_num, 2) &&
	   (rule.args[2] == word_pos_tag(word_num, -3) ||
	    rule.args[2] == word_pos_tag(word_num, -2) ||
	    rule.args[2] == word_pos_tag(word_num, -1)));
    break;
  }
  printf("ERROR!  Fell through case statement.");
  return(-1);
}

int match_rule_static(const rule_type &rule, int word_num) {
  /* here we want a fast check of whether rule applies at site */
  switch (rule.templ) {
  case NO_TEMPL:
    printf("ERROR! Instantiating args of NO_TEMPL template.");
    DEBUG_ASSERT(0);
    break;
  case T0W0:
    return(//rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_lex_tag(word_num, 0));
    break;
  case T0W1:
    return(//rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_lex_tag(word_num, 1));
    break;
  case T0W_1:
    return(//rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_lex_tag(word_num, -1));
    break;
  case T0W1W2:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_lex_tag(word_num, 1) &&
	   rule.args[2] == word_lex_tag(word_num, 2));
    break;
  case T0W_2W_1:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_lex_tag(word_num, -2) &&
	   rule.args[2] == word_lex_tag(word_num, -1));
    break;
  case T0W0W1:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_lex_tag(word_num, 0) &&
	   rule.args[2] == word_lex_tag(word_num, 1));
    break;
  case T0W_1W0:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_lex_tag(word_num, -1) &&
	   rule.args[2] == word_lex_tag(word_num, 0));
    break;
  case T0W_1W1:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_lex_tag(word_num, -1) &&
	   rule.args[2] == word_lex_tag(word_num, 1));
    break;
  case T0W123:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   (rule.args[1] == word_lex_tag(word_num, 1) ||
	    rule.args[1] == word_lex_tag(word_num, 2) ||
	    rule.args[1] == word_lex_tag(word_num, 3)));
    break;
  case T0W_3_2_1:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   (rule.args[1] == word_lex_tag(word_num, -3) ||
	    rule.args[1] == word_lex_tag(word_num, -2) ||
	    rule.args[1] == word_lex_tag(word_num, -1)));
    break;
  case T0P0:
    return(//rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_pos_tag(word_num, 0));
    break;
  case T0P1:
    return(//rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_pos_tag(word_num, 1));
    break;
  case T0P_1:
    return(//rule.args[0] == word_tag(word_num, 0) && 
	   rule.args[1] == word_pos_tag(word_num, -1));
    break;
  case T0P1P2:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_pos_tag(word_num, 1) &&
	   rule.args[2] == word_pos_tag(word_num, 2));
    break;
  case T0P_2P_1:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_pos_tag(word_num, -2) &&
	   rule.args[2] == word_pos_tag(word_num, -1));
    break;
  case T0P0P1:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_pos_tag(word_num, 0) &&
	   rule.args[2] == word_pos_tag(word_num, 1));
    break;
  case T0P_1P0:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_pos_tag(word_num, -1) &&
	   rule.args[2] == word_pos_tag(word_num, 0));
    break;
  case T0P_1P1:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   rule.args[1] == word_pos_tag(word_num, -1) &&
	   rule.args[2] == word_pos_tag(word_num, 1));
    break;
  case T0P123:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   (rule.args[1] == word_pos_tag(word_num, 1) ||
	    rule.args[1] == word_pos_tag(word_num, 2) ||
	    rule.args[1] == word_pos_tag(word_num, 3)));
    break;
  case T0P_3_2_1:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   (rule.args[1] == word_pos_tag(word_num, -3) ||
	    rule.args[1] == word_pos_tag(word_num, -2) ||
	    rule.args[1] == word_pos_tag(word_num, -1)));
    break;

  case T_1T0W0:
    return(//rule.args[0] == word_tag(word_num, -1) && 
	   //rule.args[1] == word_tag(word_num, 0) && 
	   rule.args[2] == word_lex_tag(word_num, 0));
    break;
  case T_1T0W1:
    return(//rule.args[0] == word_tag(word_num, -1) && 
	   //rule.args[1] == word_tag(word_num, 0) && 
	   rule.args[2] == word_lex_tag(word_num, 1));
    break;
  case T_1T0W_1:
    return(//rule.args[0] == word_tag(word_num, -1) && 
	   //rule.args[1] == word_tag(word_num, 0) && 
	   rule.args[2] == word_lex_tag(word_num, -1));
    break;
  case T_1T0W1W2:
    return(//rule.args[0] == word_tag(word_num, -1) && 
	   //rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_lex_tag(word_num, 1) &&
	   rule.args[3] == word_lex_tag(word_num, 2));
    break;
  case T_1T0W_2W_1:
    return(//rule.args[0] == word_tag(word_num, -1) && 
	   //rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_lex_tag(word_num, -2) &&
	   rule.args[3] == word_lex_tag(word_num, -1));
    break;
  case T_1T0W0W1:
    return(//rule.args[0] == word_tag(word_num, -1) && 
	   //rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_lex_tag(word_num, 0) &&
	   rule.args[3] == word_lex_tag(word_num, 1));
    break;
  case T_1T0W_1W0:
    return(//rule.args[0] == word_tag(word_num, -1) && 
	   //rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_lex_tag(word_num, -1) &&
	   rule.args[3] == word_lex_tag(word_num, 0));
    break;
  case T_1T0W_1W1:
    return(//rule.args[0] == word_tag(word_num, -1) && 
	   //rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_lex_tag(word_num, -1) &&
	   rule.args[3] == word_lex_tag(word_num, 1));
    break;
  case T_1T0W123:
    return(//rule.args[0] == word_tag(word_num, -1) &&
	   //rule.args[1] == word_tag(word_num, 0) &&
	   (rule.args[2] == word_lex_tag(word_num, 1) ||
	    rule.args[2] == word_lex_tag(word_num, 2) ||
	    rule.args[2] == word_lex_tag(word_num, 3)));
    break;
  case T_1T0W_3_2_1:
    return(//rule.args[0] == word_tag(word_num, -1) &&
	   //rule.args[1] == word_tag(word_num, 0) &&
	   (rule.args[2] == word_lex_tag(word_num, -3) ||
	    rule.args[2] == word_lex_tag(word_num, -2) ||
	    rule.args[2] == word_lex_tag(word_num, -1)));
    break;
  case T_1T0P0:
    return(//rule.args[0] == word_tag(word_num, -1) && 
	   //rule.args[1] == word_tag(word_num, 0) && 
	   rule.args[2] == word_pos_tag(word_num, 0));
    break;
  case T_1T0P1:
    return(//rule.args[0] == word_tag(word_num, -1) && 
	   //rule.args[1] == word_tag(word_num, 0) && 
	   rule.args[2] == word_pos_tag(word_num, 1));
    break;
  case T_1T0P_1:
    return(//rule.args[0] == word_tag(word_num, -1) && 
	   //rule.args[1] == word_tag(word_num, 0) && 
	   rule.args[2] == word_pos_tag(word_num, -1));
    break;
  case T_1T0P1P2:
    return(//rule.args[0] == word_tag(word_num, -1) && 
	   //rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_pos_tag(word_num, 1) &&
	   rule.args[3] == word_pos_tag(word_num, 2));
    break;
  case T_1T0P_2P_1:
    return(//rule.args[0] == word_tag(word_num, -1) && 
	   //rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_pos_tag(word_num, -2) &&
	   rule.args[3] == word_pos_tag(word_num, -1));
    break;
  case T_1T0P0P1:
    return(//rule.args[0] == word_tag(word_num, -1) && 
	   //rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_pos_tag(word_num, 0) &&
	   rule.args[3] == word_pos_tag(word_num, 1));
    break;
  case T_1T0P_1P0:
    return(//rule.args[0] == word_tag(word_num, -1) && 
	   //rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_pos_tag(word_num, -1) &&
	   rule.args[3] == word_pos_tag(word_num, 0));
    break;
  case T_1T0P_1P1:
    return(//rule.args[0] == word_tag(word_num, -1) && 
	   //rule.args[1] == word_tag(word_num, 0) &&
	   rule.args[2] == word_pos_tag(word_num, -1) &&
	   rule.args[3] == word_pos_tag(word_num, 1));
    break;
  case T_1T0P123:
    return(//rule.args[0] == word_tag(word_num, -1) &&
	   //rule.args[1] == word_tag(word_num, 0) &&
	   (rule.args[2] == word_pos_tag(word_num, 1) ||
	    rule.args[2] == word_pos_tag(word_num, 2) ||
	    rule.args[2] == word_pos_tag(word_num, 3)));
    break;
  case T_1T0P_3_2_1:
    return(//rule.args[0] == word_tag(word_num, -1) &&
	   //rule.args[1] == word_tag(word_num, 0) &&
	   (rule.args[2] == word_pos_tag(word_num, -3) ||
	    rule.args[2] == word_pos_tag(word_num, -2) ||
	    rule.args[2] == word_pos_tag(word_num, -1)));
    break;

  case T0T1W0:
    return(//rule.args[0] == word_tag(word_num, 0) && 
	   //rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_lex_tag(word_num, 0));
    break;
  case T0T1W1:
    return(//rule.args[0] == word_tag(word_num, 0) && 
	   //rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_lex_tag(word_num, 1));
    break;
  case T0T1W_1:
    return(//rule.args[0] == word_tag(word_num, 0) && 
	   //rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_lex_tag(word_num, -1));
    break;
  case T0T1W1W2:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   //rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_lex_tag(word_num, 1) &&
	   rule.args[3] == word_lex_tag(word_num, 2));
    break;
  case T0T1W_2W_1:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   //rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_lex_tag(word_num, -2) &&
	   rule.args[3] == word_lex_tag(word_num, -1));
    break;
  case T0T1W0W1:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   //rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_lex_tag(word_num, 0) &&
	   rule.args[3] == word_lex_tag(word_num, 1));
    break;
  case T0T1W_1W0:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   //rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_lex_tag(word_num, -1) &&
	   rule.args[3] == word_lex_tag(word_num, 0));
    break;
  case T0T1W_1W1:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   //rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_lex_tag(word_num, -1) &&
	   rule.args[3] == word_lex_tag(word_num, 1));
    break;
  case T0T1W123:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   //rule.args[1] == word_tag(word_num, 1) &&
	   (rule.args[2] == word_lex_tag(word_num, 1) ||
	    rule.args[2] == word_lex_tag(word_num, 2) ||
	    rule.args[2] == word_lex_tag(word_num, 3)));
    break;
  case T0T1W_3_2_1:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   //rule.args[1] == word_tag(word_num, 1) &&
	   (rule.args[2] == word_lex_tag(word_num, -3) ||
	    rule.args[2] == word_lex_tag(word_num, -2) ||
	    rule.args[2] == word_lex_tag(word_num, -1)));
    break;
  case T0T1P0:
    return(//rule.args[0] == word_tag(word_num, 0) && 
	   //rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_pos_tag(word_num, 0));
    break;
  case T0T1P1:
    return(//rule.args[0] == word_tag(word_num, 0) && 
	   //rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_pos_tag(word_num, 1));
    break;
  case T0T1P_1:
    return(//rule.args[0] == word_tag(word_num, 0) && 
	   //rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_pos_tag(word_num, -1));
    break;
  case T0T1P1P2:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   //rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_pos_tag(word_num, 1) &&
	   rule.args[3] == word_pos_tag(word_num, 2));
    break;
  case T0T1P_2P_1:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   //rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_pos_tag(word_num, -2) &&
	   rule.args[3] == word_pos_tag(word_num, -1));
    break;
  case T0T1P0P1:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   //rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_pos_tag(word_num, 0) &&
	   rule.args[3] == word_pos_tag(word_num, 1));
    break;
  case T0T1P_1P0:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   //rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_pos_tag(word_num, -1) &&
	   rule.args[3] == word_pos_tag(word_num, 0));
    break;
  case T0T1P_1P1:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   //rule.args[1] == word_tag(word_num, 1) && 
	   rule.args[2] == word_pos_tag(word_num, -1) &&
	   rule.args[3] == word_pos_tag(word_num, 1));
    break;
  case T0T1P123:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   //rule.args[1] == word_tag(word_num, 1) &&
	   (rule.args[2] == word_pos_tag(word_num, 1) ||
	    rule.args[2] == word_pos_tag(word_num, 2) ||
	    rule.args[2] == word_pos_tag(word_num, 3)));
    break;
  case T0T1P_3_2_1:
    return(//rule.args[0] == word_tag(word_num, 0) &&
	   //rule.args[1] == word_tag(word_num, 1) &&
	   (rule.args[2] == word_pos_tag(word_num, -3) ||
	    rule.args[2] == word_pos_tag(word_num, -2) ||
	    rule.args[2] == word_pos_tag(word_num, -1)));
    break;

  case T_2T_1W0:
    return(//rule.args[0] == word_tag(word_num, -2) && 
	   //rule.args[1] == word_tag(word_num, -1) && 
	   rule.args[2] == word_lex_tag(word_num, 0));
    break;
  case T_2T_1W1:
    return(//rule.args[0] == word_tag(word_num, -2) && 
	   //rule.args[1] == word_tag(word_num, -1) && 
	   rule.args[2] == word_lex_tag(word_num, 1));
    break;
  case T_2T_1W_1:
    return(//rule.args[0] == word_tag(word_num, -2) && 
	   //rule.args[1] == word_tag(word_num, -1) && 
	   rule.args[2] == word_lex_tag(word_num, -1));
    break;
  case T_2T_1W1W2:
    return(//rule.args[0] == word_tag(word_num, -2) && 
	   //rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_lex_tag(word_num, 1) &&
	   rule.args[3] == word_lex_tag(word_num, 2));
    break;
  case T_2T_1W_2W_1:
    return(//rule.args[0] == word_tag(word_num, -2) && 
	   //rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_lex_tag(word_num, -2) &&
	   rule.args[3] == word_lex_tag(word_num, -1));
    break;
  case T_2T_1W0W1:
    return(//rule.args[0] == word_tag(word_num, -2) && 
	   //rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_lex_tag(word_num, 0) &&
	   rule.args[3] == word_lex_tag(word_num, 1));
    break;
  case T_2T_1W_1W0:
    return(//rule.args[0] == word_tag(word_num, -2) && 
	   //rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_lex_tag(word_num, -1) &&
	   rule.args[3] == word_lex_tag(word_num, 0));
    break;
  case T_2T_1W_1W1:
    return(//rule.args[0] == word_tag(word_num, -2) && 
	   //rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_lex_tag(word_num, -1) &&
	   rule.args[3] == word_lex_tag(word_num, 1));
    break;
  case T_2T_1W123:
    return(//rule.args[0] == word_tag(word_num, -2) &&
	   //rule.args[1] == word_tag(word_num, -1) &&
	   (rule.args[2] == word_lex_tag(word_num, 1) ||
	    rule.args[2] == word_lex_tag(word_num, 2) ||
	    rule.args[2] == word_lex_tag(word_num, 3)));
    break;
  case T_2T_1W_3_2_1:
    return(//rule.args[0] == word_tag(word_num, -2) &&
	   //rule.args[1] == word_tag(word_num, -1) &&
	   (rule.args[2] == word_lex_tag(word_num, -3) ||
	    rule.args[2] == word_lex_tag(word_num, -2) ||
	    rule.args[2] == word_lex_tag(word_num, -1)));
    break;
  case T_2T_1P0:
    return(//rule.args[0] == word_tag(word_num, -2) && 
	   //rule.args[1] == word_tag(word_num, -1) && 
	   rule.args[2] == word_pos_tag(word_num, 0));
    break;
  case T_2T_1P1:
    return(//rule.args[0] == word_tag(word_num, -2) && 
	   //rule.args[1] == word_tag(word_num, -1) && 
	   rule.args[2] == word_pos_tag(word_num, 1));
    break;
  case T_2T_1P_1:
    return(//rule.args[0] == word_tag(word_num, -2) && 
	   //rule.args[1] == word_tag(word_num, -1) && 
	   rule.args[2] == word_pos_tag(word_num, -1));
    break;
  case T_2T_1P1P2:
    return(//rule.args[0] == word_tag(word_num, -2) && 
	   //rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_pos_tag(word_num, 1) &&
	   rule.args[3] == word_pos_tag(word_num, 2));
    break;
  case T_2T_1P_2P_1:
    return(//rule.args[0] == word_tag(word_num, -2) && 
	   //rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_pos_tag(word_num, -2) &&
	   rule.args[3] == word_pos_tag(word_num, -1));
    break;
  case T_2T_1P0P1:
    return(//rule.args[0] == word_tag(word_num, -2) && 
	   //rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_pos_tag(word_num, 0) &&
	   rule.args[3] == word_pos_tag(word_num, 1));
    break;
  case T_2T_1P_1P0:
    return(//rule.args[0] == word_tag(word_num, -2) && 
	   //rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_pos_tag(word_num, -1) &&
	   rule.args[3] == word_pos_tag(word_num, 0));
    break;
  case T_2T_1P_1P1:
    return(//rule.args[0] == word_tag(word_num, -2) && 
	   //rule.args[1] == word_tag(word_num, -1) &&
	   rule.args[2] == word_pos_tag(word_num, -1) &&
	   rule.args[3] == word_pos_tag(word_num, 1));
    break;
  case T_2T_1P123:
    return(//rule.args[0] == word_tag(word_num, -2) &&
	   //rule.args[1] == word_tag(word_num, -1) &&
	   (rule.args[2] == word_pos_tag(word_num, 1) ||
	    rule.args[2] == word_pos_tag(word_num, 2) ||
	    rule.args[2] == word_pos_tag(word_num, 3)));
    break;
  case T_2T_1P_3_2_1:
    return(//rule.args[0] == word_tag(word_num, -2) &&
	   //rule.args[1] == word_tag(word_num, -1) &&
	   (rule.args[2] == word_pos_tag(word_num, -3) ||
	    rule.args[2] == word_pos_tag(word_num, -2) ||
	    rule.args[2] == word_pos_tag(word_num, -1)));
    break;

  case T1T2W0:
    return(//rule.args[0] == word_tag(word_num, 1) && 
	   //rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_lex_tag(word_num, 0));
    break;
  case T1T2W1:
    return(//rule.args[0] == word_tag(word_num, 1) && 
	   //rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_lex_tag(word_num, 1));
    break;
  case T1T2W_1:
    return(//rule.args[0] == word_tag(word_num, 1) && 
	   //rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_lex_tag(word_num, -1));
    break;
  case T1T2W1W2:
    return(//rule.args[0] == word_tag(word_num, 1) &&
	   //rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_lex_tag(word_num, 1) &&
	   rule.args[3] == word_lex_tag(word_num, 2));
    break;
  case T1T2W_2W_1:
    return(//rule.args[0] == word_tag(word_num, 1) &&
	   //rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_lex_tag(word_num, -2) &&
	   rule.args[3] == word_lex_tag(word_num, -1));
    break;
  case T1T2W0W1:
    return(//rule.args[0] == word_tag(word_num, 1) &&
	   //rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_lex_tag(word_num, 0) &&
	   rule.args[3] == word_lex_tag(word_num, 1));
    break;
  case T1T2W_1W0:
    return(//rule.args[0] == word_tag(word_num, 1) &&
	   //rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_lex_tag(word_num, -1) &&
	   rule.args[3] == word_lex_tag(word_num, 0));
    break;
  case T1T2W_1W1:
    return(//rule.args[0] == word_tag(word_num, 1) &&
	   //rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_lex_tag(word_num, -1) &&
	   rule.args[3] == word_lex_tag(word_num, 1));
    break;
  case T1T2W123:
    return(//rule.args[0] == word_tag(word_num, 1) &&
	   //rule.args[1] == word_tag(word_num, 2) &&
	   (rule.args[2] == word_lex_tag(word_num, 1) ||
	    rule.args[2] == word_lex_tag(word_num, 2) ||
	    rule.args[2] == word_lex_tag(word_num, 3)));
    break;
  case T1T2W_3_2_1:
    return(//rule.args[0] == word_tag(word_num, 1) &&
	   //rule.args[1] == word_tag(word_num, 2) &&
	   (rule.args[2] == word_lex_tag(word_num, -3) ||
	    rule.args[2] == word_lex_tag(word_num, -2) ||
	    rule.args[2] == word_lex_tag(word_num, -1)));
    break;
  case T1T2P0:
    return(//rule.args[0] == word_tag(word_num, 1) && 
	   //rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_pos_tag(word_num, 0));
    break;
  case T1T2P1:
    return(//rule.args[0] == word_tag(word_num, 1) && 
	   //rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_pos_tag(word_num, 1));
    break;
  case T1T2P_1:
    return(//rule.args[0] == word_tag(word_num, 1) && 
	   //rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_pos_tag(word_num, -1));
    break;
  case T1T2P1P2:
    return(//rule.args[0] == word_tag(word_num, 1) &&
	   //rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_pos_tag(word_num, 1) &&
	   rule.args[3] == word_pos_tag(word_num, 2));
    break;
  case T1T2P_2P_1:
    return(//rule.args[0] == word_tag(word_num, 1) &&
	   //rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_pos_tag(word_num, -2) &&
	   rule.args[3] == word_pos_tag(word_num, -1));
    break;
  case T1T2P0P1:
    return(//rule.args[0] == word_tag(word_num, 1) &&
	   //rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_pos_tag(word_num, 0) &&
	   rule.args[3] == word_pos_tag(word_num, 1));
    break;
  case T1T2P_1P0:
    return(//rule.args[0] == word_tag(word_num, 1) &&
	   //rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_pos_tag(word_num, -1) &&
	   rule.args[3] == word_pos_tag(word_num, 0));
    break;
  case T1T2P_1P1:
    return(//rule.args[0] == word_tag(word_num, 1) &&
	   //rule.args[1] == word_tag(word_num, 2) && 
	   rule.args[2] == word_pos_tag(word_num, -1) &&
	   rule.args[3] == word_pos_tag(word_num, 1));
    break;
  case T1T2P123:
    return(//rule.args[0] == word_tag(word_num, 1) &&
	   //rule.args[1] == word_tag(word_num, 2) &&
	   (rule.args[2] == word_pos_tag(word_num, 1) ||
	    rule.args[2] == word_pos_tag(word_num, 2) ||
	    rule.args[2] == word_pos_tag(word_num, 3)));
    break;
  case T1T2P_3_2_1:
    return(//rule.args[0] == word_tag(word_num, 1) &&
	   //rule.args[1] == word_tag(word_num, 2) &&
	   (rule.args[2] == word_pos_tag(word_num, -3) ||
	    rule.args[2] == word_pos_tag(word_num, -2) ||
	    rule.args[2] == word_pos_tag(word_num, -1)));
    break;
  }
  printf("ERROR!  Fell through case statement.");
  return(-1);
}

