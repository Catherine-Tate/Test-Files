import string
import random
import codecs

def findpass(oldpass, passtring):
    print(hex(oldpass))
    if oldpass <= 0:
        if oldpass != 0:
            passtring = ""
            oldpass = 0x2d64a
            return(findpass(oldpass, passtring))
        return passtring
    oldpass >>= 0x1
    char = random.choice(string.ascii_letters)
    charnum = ord(char)
    oldpass -= charnum
    passtring += char
    return(findpass(oldpass, passtring))




passtring = ""
fin = 0x2d64a

passtring = findpass(fin, passtring)
print(passtring)
