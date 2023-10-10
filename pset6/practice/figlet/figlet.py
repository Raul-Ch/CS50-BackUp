from sys import argv, exit
# The documentation for pyfiglet isn’t very clear, but you can use the module as follows:
from pyfiglet import Figlet
import random

figlet = Figlet()
fonts = figlet.getFonts()

if len(argv) < 4:
    if argv[1] not in ["-f","--font"]:
        exit("Invalid usage")
    else:
         figlet.setFont(font = fonts[random.randrange(len(fonts))])

    if len(argv) > 1:
        if argv[2] in fonts:
            figlet.setFont(font = argv[2])
        else:
            exit("Invalid usage")

    s = input("Input: ")

    # And you can output text in that font with code like this, wherein s is that text as a str:
    print(figlet.renderText(s))

else:
    exit("Invalid usage last")

