from sys import argv, exit
# The documentation for pyfiglet isn’t very clear, but you can use the module as follows:
from pyfiglet import Figlet
import random

figlet = Figlet()
fonts = figlet.getFonts()

#def main
def main():
    s = input("Input: ")

    # And you can output text in that font with code like this, wherein s is that text as a str:
    print(figlet.renderText(s))

if len(argv) == 2:
    if argv[1] in ["-f","--font"]:
         figlet.setFont(font = fonts[random.randrange(len(fonts))])
         main()
    else:
        exit("Invalid usage")

elif len(argv) == 3:
    if argv[2] in fonts:
            figlet.setFont(font = argv[2])
            main()
        else:
            exit("Invalid usage")
else:
    exit("Invalid usage last")
