# TMGVD1
Proyecto 1 de Tópicos en manejo de grandes volúmenes de datos

HLL Mods: Intersección, Jaccard Distance, Diferencia Simétrica

UTILS: https://agkn.wordpress.com/2013/04/02/sketch-of-the-day-probabilistic-counting-with-stochastic-averaging-pcsa/

Las instrucciones de uso son las siguientes:

  -La depuracion del archivo, para que los programas de analisis funcionen de manera correcta, se necesita que primero todo el archivo de texto este en mayusculas, 
   para esto se puede utilizar el comando $ sed -e 's/\(.*\)/\U\1/' nombrearchivo  > output , luego necesitamos eliminar todas las lineas que comiencen con el 
   caracter '>', para esto se puede utilizar el comando el comando $ grep -wv '>' > nombrearchivo  y finalmente debemos eliminar los caracteres 'N', para esto podemos
   utilizar el comando $ sed -i -e 's/\(N\)//g' nombrearchivo, asi tendremos el archivo ideal para la utilizacion de los programas pedidos.

  -Para el uso de HyperLogLog primero se debe compilar, usando su compilador de c++ de preferencia, el codigo HLL_FINAL.cpp, luego se debe ejecutar el codigo,
   al ejecutarse el codigo este pedira un archivo al cual se le aplicara HyperLogLog, para encontrar la cantidad de kmers iguales en el archivo, para ingresar
   el archivo solo se necesita escribir el nombre del archivo, con su extension correspondiente, y presionar enter, cabe mencionar que el archivo que se quiere
   analizar debe estar en la misma carpeta que el archivo HLL_FINAL.cpp. Finalmente el programa entregara el aproximado de kmers iguales en el archivo entregado.
   
  -Para el uso de PCSA primero se debe compilar, usando su compilador de c++ de preferencia, el codigo PCSA.cpp, luego se debe ejecutar el codigo,
   al ejecutarse el codigo, este pedira un archivo al cual se le aplicara PCSA, para encontrar la cantidad de kmers iguales en el archivo, para ingresar
   el archivo, solo se necesita escribir el nombre del archivo, con su extension correspondiente, y presionar enter, cabe mencionar que el archivo que se quiere
   analizar debe estar en la misma carpeta que el archivo PCSA.cpp. Finalmente el programa entregara el aproximado de kmers iguales en el archivo entregado.
