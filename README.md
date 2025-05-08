# Laboratorio-1-Rob-tica

NOMBRE INTEGRANTES: 
- Alex Aravena
- Samria Becerra Saa
- Álvaro Catalán
- Leandro Chamorro

PARTE 1 - PREGUNTAS 

• ¿ Qué función cumple los sensores, actuadores y controladores en el
robot?

La función que cumplen son las siguientes: 
Sensores: los sensores son los órganos de los sentidos de robot y le permiten entender su entorno, tomar decisiones y actuar de manera autónoma.
Actuadores: la función de los actuadores es convertir la energía en movimiento o fuerza, permitiendo que el robot realice acciones físicas como moverse, girar o sujetar objetos
Controladores: los función de los controladores es recibir la información de los sensores y procesar esa información según un algoritmo y envían ordenes a los actuadores actúe de acuerdo a sus objetivos

• ¿ Cómo se puede estimar la velocidad sin encoders?

Si no utilizamos encoders,  podemos estimar la velocidad con los siguientes métodos:
-Sensores de efecto Hall o magnetómetros: permiten detectar rotaciones al colocar imanes en el eje del motor. Cada vez que el campo magnético cambia, el sensor genera una señal, y con ello se puede calcular la velocidad angular.
-Medición de distancia recorrida en un tiempo conocido: utilizando sensores como ultrasónicos, LIDAR o visión artificial, se puede estimar cuánto ha avanzado el robot en cierto tiempo. Dividiendo la distancia entre el tiempo, se obtiene una estimación de la velocidad.
-Modelo del motor con PWM: si se conoce el comportamiento del motor, es posible estimar su velocidad en función de la señal de control (como el ancho de pulso del PWM). Esto requiere una calibración previa para saber, por ejemplo, a qué velocidad gira el motor con un determinado porcentaje de PWM.

• ¿ Cómo afecta la falta de encoders a la precisión del movimiento?

La falta de encoders afecta negativamente la precisión del movimiento de un robot, pues:

- El sistema no puede verificar si el motor realmente se mueve a la velocidad esperada ni cuánta distancia ha recorrido. Esto significa que el control es en lazo abierto (open-loop), lo que aumenta la posibilidad de errores.
- Sin mediciones precisas del desplazamiento, pequeños errores en velocidad o dirección se acumulan con el tiempo, provocando desviaciones significativas en trayectorias largas.
- Si un motor gira más rápido que otro, el robot puede desviarse, y sin encoders no hay forma automática de detectar ni corregir esa diferencia.
- Cambios en la fricción, carga o nivel de batería pueden alterar el comportamiento del motor. Sin encoders, el sistema no detecta estos cambios y no ajusta la salida, lo que reduce aún más la precisión.

• ¿ Qué es PWM y cómo ayuda a controlar la velocidad de los motores?

Las señales PWM (Pulse Width Modulation o Modulación por Ancho de Pulso) es una técnica utilizada para controlar la potencia que se le suministra a un dispositivo, variando el ciclo de trabajo de una señal digital. PWM convierte una señal digital a una analógica, permitiendo controlar la velocidad del motor. (Motores DC y Servomotores)

• ¿ Cómo afecta el control de velocidad a la precisión de la navegación
sin encoders?

Sin encoders, el robot no puede medir directamente la velocidad real de sus motores, por lo que el control se basa solo en estimaciones (como el valor de PWM). Esto provoca mayor imprecisión en el movimiento, ya que no se pueden detectar ni corregir diferencias entre motores, ni adaptarse a cambios como la fricción o el peso. Como resultado, la navegación se vuelve menos precisa, especialmente en trayectorias largas o que requieren giros controlados.


PARTE 2 - PREGUNTAS

¿Cómo se calcula la velocidad del robot sin encoders usando PWM?

Respuesta: Como el PWM puede controlar la cantidad de voltaje suministrada, se puede calcular experimentalmente la velocidad en base al valor de PWM, entonces, mientras mayor sea el PWM, mayor será la velocidad. A partir de ahí se podría hacer una tabla de valores para que a partir del PWM saber la velocidad que tendrá.

¿Cómo factores afectan la trayectoria y velocidad del robot al cambiar los intervalos de tiempo?

Intervalos de tiempo más cortos pueden afectar de manera positiva para el cálculo de la trayectoria, puesto que estos al ser más repetitivos, puede tener una trayectoria más precisa.

Mientras tanto, la velocidad no se debería ver afectada por los intervalos de tiempo, puesto que si es que estos son más amplios o más cortos, la fórmula sigue siendo la misma v = d/t, en donde si es que el robot se mueve en una distancia de manera constante, se mantendría en proporción con el tiempo, ahora, si es que el robot tiene una velocidad irregular, no sería lo mejor que fueran intervalos de tiempo muy grandes, puesto que lo hace más susceptible a errores de calculo o desviaciones.

¿Cuáles son las ventajas y desventajas de usar un IMU para ajustar la dirección en lugar de encoders?

Cómo los encoders miden las vueltas que da una rueda, son mas precisos al medir la distancia y dirección, pero por lo mismo, dependen de un buen contacto de las ruedas con el suelo para ser eficientes. Mientras que el IMU puede ajustar la dirección sin depender de las ruedas, siendo más útil en terrenos irregulares, la desventaja que tiene es que requiere de una calibración constante. El IMU también es mejor midiendo y detectando inclinaciones y giros rápidos del robot, mientras que los encoders funcionan mejor para trayectorias largas y definidas.

¿Qué efecto tiene la inclinación o el giro en el movimiento del robot, y cómo se corrige con el IMU?

La inclinación o el giro en el movimiento del robot afectan en la estabilidad y dirección del mismo, provocando que se pueda desviar de su trayectoria. El IMU detecta estos cambios con el acelerómetro y el giroscopio, información con la cual el robot puede ajustar la velocidad de los motores o la dirección.
