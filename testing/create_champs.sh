#!/bin/sh



./asm-test champs_for_etalon/42.s
./asm-test champs_for_etalon/Backward.s
./asm-test champs_for_etalon/barriere.s
./asm-test champs_for_etalon/bee_gees.s
./asm-test champs_for_etalon/bigzork.s
./asm-test champs_for_etalon/Car.s
./asm-test champs_for_etalon/Gagnant.s
./asm-test champs_for_etalon/jumper.s
./asm-test champs_for_etalon/toto.s
./asm-test champs_for_etalon/mortel.s
./asm-test champs_for_etalon/new.s
./asm-test champs_for_etalon/sebc.s


echo "asm |||||||||||||||||||||||||||"


./asm champs_for_our_project/42.s
./asm champs_for_our_project/Backward.s
./asm champs_for_our_project/barriere.s
./asm champs_for_our_project/bee_gees.s
./asm champs_for_our_project/bigzork.s
./asm champs_for_our_project/Car.s
./asm champs_for_our_project/Gagnant.s
./asm champs_for_our_project/jumper.s
./asm champs_for_our_project/toto.s
./asm champs_for_our_project/mortel.s
./asm champs_for_our_project/new.s
./asm champs_for_our_project/sebc.s

echo "======================================================="

./asm-test valid_champs_etalon/42.s
./asm-test valid_champs_etalon/barriere.s
./asm-test valid_champs_etalon/bee_gees.s
./asm-test valid_champs_etalon/Gagnant.s
./asm-test valid_champs_etalon/kamelkaze.s
./asm-test valid_champs_etalon/katchup.s
./asm-test valid_champs_etalon/tchupka.s

echo "asm |||||||||||||||||||||||||||"

./asm valid_champs_our/42.s
./asm valid_champs_our/barriere.s
./asm valid_champs_our/bee_gees.s
./asm valid_champs_our/Gagnant.s
./asm valid_champs_our/kamelkaze.s
./asm valid_champs_our/katchup.s
./asm valid_champs_our/tchupka.s

echo "DONE CREATE CHAMPIONS"
