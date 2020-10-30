#!/bin/sh




./asm-test check_wrong/unknown_instruction.s
./asm-test check_wrong/wrong_argument.s
./asm-test check_wrong/wrong_character_label.s
./asm-test check_wrong/wrong_lexical.s
./asm-test check_wrong/wrong_refer.s
./asm-test check_wrong/long_name.s
./asm-test check_wrong/without_code.s
./asm-test check_wrong/without_comment.s
./asm-test check_wrong/without_name.s
./asm-test check_wrong/without_type.s






echo "======================================================="


./asm check_wrong/unknown_instruction.s
./asm check_wrong/wrong_argument.s
./asm check_wrong/wrong_character_label.s
./asm check_wrong/wrong_lexical.s
./asm check_wrong/wrong_refer.s
./asm check_wrong/long_name.s
./asm check_wrong/without_code.s
./asm check_wrong/without_comment.s
./asm check_wrong/without_name.s
./asm check_wrong/without_type.s


echo "DONE CREATE CHAMPIONS"
