filename = input()
f = open(str(filename),"r")
content = f.read()
content.upper();
final_content = content.translate({ ord(c): None for c in "N>" })
f2 = open(str(filename), "w")
f2.write(str(final_content))
f2.close()
f.close()
#print(content)
