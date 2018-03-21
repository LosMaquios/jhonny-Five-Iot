# jhonny-Five-Iot 
 Este proyecto busca trabajar con el framework JOHNNY-FIVE  de codigo abierto.Este framework esta basado en el protocolo firmata.

# Requerimientos
  Para poder bajar este proyecto es necesario contar con:
  -Node
  -npm
  

# Primeros pasos para trabajar con jhonny-five 
1- Si estas trabajando desde S.O linux por cuestiones de permisos tienes que ir al path y darle permisos de accesos al dispositivo
<br>
<code> chmod 777 /dev/tty </code>
<br>
2- Teniendo ya node y npm vamos agregar la libreria de de jhonny-five de la siguiente manera 
<br>
<code> npm install jhonny-five </code>
<br>
3- Solo faltaria agregar la libreria que por medio del protocolo firmata nos permite acceder al dispositivo o placa con la cual vamos a trabajar 
<br>
<code>npm install firmata party  </code>

4- Desde nuestro archivo <code> package.json </code> donde se encuentra las ejecuciones por medios de escript vamos a agregar lo siguiente
<br>
<code>  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1",
    "reset": "firmata-party uno --debug"
  }, </code>
  <br>
  5- para ejecutar el .js donde tenemos nuestro codigo ejecutaremos lo siguiente
  <br>
  <code>node index.js  </code>
  
  # Para trabajar en este repositorio
  
  solo faltaria hacer un 
  <br>
  <code>npm install </code>
# Arduino  
 Este proyecto sera trabajado más que todo con el arduino one.
 
 # Implementación
 Se busca hacer una implementación de diferentes componentes realizados con la libreria de jhonny five 
