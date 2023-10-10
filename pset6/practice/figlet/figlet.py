from pyfiglet import Figlet

# The documentation for pyfiglet isn’t very clear, but you can use the module as follows:
from pyfiglet import Figlet

figlet = Figlet()

# You can then get a list of available fonts with code like this:
figlet.getFonts()

# You can set the font with code like this, wherein f is the font’s name as a str:

figlet.setFont(font=f)


# And you can output text in that font with code like this, wherein s is that text as a str:
print(figlet.renderText(s))