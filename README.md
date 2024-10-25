# KimchiReader-Auto-Status
This C program will make it so you can write words into your terminal and it will count how many times you've seen the noticed words. Handy for if you hate putting words on known and seen while immersing.


##Advice on how to use it. 
copy words to a txt file or clipboard that you have looked up or noticed during your immersion, the words must be unknown words or seen words. 

Then do ./korean add (words) and put the words without Parentheses, this will add the words to the database.
Also if you notice multiple of the same words then still add the duplicates. The program is made to count the notices up for each word until you hit the SEENCAP(having noticed a word 2 times total,) or KNOWNCAP(having noticed a word 7 times total,) you can also change this cap by going into the c code and changing the settings.
Then recompile it with the command "gcc -o korean korean.c" this will update the program.

After that you can check if you should put words on known or seen by using the command
./korean check, it will show you a list of seen or known words if you have hit the cap with some words.
copy these words onto your language learning app and paste them so that you can put those words on seen or known.

Lastly, after having put the words on seen or known, 
use ./korean updateStatus to update the database with knowledge that you put the words on seen and known in the application that you like.
This will sync them basically and also make it so that they don't appear anymore until a new cap is met.

if you need help while using the tool.
use ./korean -h or --help. This will display a page in your terminal with explanations for each command.


##-- extra credit
credit to Chooky for pointing out a segfault bug to me.