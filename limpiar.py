filename = input()
f = open(str(filename),"r")
content = f.read()
content.upper();
final_content = content.translate({ ord(c): None for c in "N>" })
f2 = open(str(filename)+str(2), "w")
for line in content:
    line.upper()
f2.write(content)
f2.close()
f.close()
#print(content)
