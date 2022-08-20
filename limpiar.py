filename = input()
f = open(str(filename),"r")
content = f.read()
content.upper();
final_content = content.translate({ ord(c): None for c in "N>" })
f.write(str(final_content))
#print(content)
