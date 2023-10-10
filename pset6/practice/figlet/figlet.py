from sys import argv, exit
# The documentation for pyfiglet isn’t very clear, but you can use the module as follows:
from pyfiglet import Figlet

figlet = Figlet()

if len(argv) == 1:
    if argv[1] not in ["-f","--font"]:
        break

elif leng(argv) == 2:
    # You can then get a list of available fonts with code like this:
    if argv[2] not in [figlet.getFonts()]:
        break
    else:
        # You can set the font with code like this, wherein f is the font’s name as a str:
        figlet.setFont(font=argv[2])

input("Input: ")

# And you can output text in that font with code like this, wherein s is that text as a str:
print("Output", figlet.renderText(s))

else
    exit("Invalid usage")