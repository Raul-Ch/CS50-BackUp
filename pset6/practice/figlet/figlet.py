from sys import argv, exit
# The documentation for pyfiglet isn’t very clear, but you can use the module as follows:
from pyfiglet import Figlet

figlet = Figlet()
fonts = figlet.getFonts():

if len(argv) > 1 or len(argv) < 4:
    if argv[2] not in ["-f","--font"]:
        exit("Invalid usage")
    else:
         figlet.setFont(fonts[random.randrange(len(fonts))])

    if len(argv) > 2:
        if argv[3] in fonts:
            figlet.setFont(font = argv[3])
        else:
            exit("Invalid usage")

    s = input("Input: ")

    # And you can output text in that font with code like this, wherein s is that text as a str:
    print(figlet.renderText(s))

else:
    exit("Invalid usage last")

