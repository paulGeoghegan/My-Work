@ECHO OFF 
gcc admin.c character.c inventory.c itemPickUp.c items.c map.c menu.c play.c save.c tiles.c utility.c -g -o trialsByText.out
gdb trialsByText.out