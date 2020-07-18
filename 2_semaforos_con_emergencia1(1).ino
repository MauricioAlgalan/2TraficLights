/*Pines del semaforo 1
  Verde 3
  Amarillo 5
  Rojo 6
*/

/*
 1st Trafic lights pins:
 Green 3
 Yellow 5
 Red 6
*/

int Semaforo1Verde=3;
int Semaforo1Amarillo=5;
int Semaforo1Rojo=6;



/*Pines del semaforo 2
  Verde 9
  Amarillo 10
  Rojo 11
*/

/*2nd trafic lights pins
  Green 9
  Yellow 10
  Red 11
*/

int Semaforo2Verde=9;
int Semaforo2Amarillo=10;
int Semaforo2Rojo=11;


//Estado del led Semaforo
//Initial state of the trafic lights
int EstadoS1VLed=HIGH;
int EstadoS1ALed=LOW;
int EstadoS1RLed=LOW;
int EstadoS2VLed=LOW;
int EstadoS2ALed=LOW;
int EstadoS2RLed=HIGH;

/*Variable que medirá el tiempo
  Time count variable
*/
unsigned long milisegundos=0;

/*Variablas para activar la emergencia
  Emergency state variables
*/
int Emergencia=0;
int EstadoActivacion=0;
int CambioEstado=0;
int TiempoActivacion=0;

/*Pin del sensor de emergencia
  Emergency sensor pin
*/
int PinEmergencia=2;


//Estado Inicial
//Initial setup
void setup()
{
  //Configurando los pines del semaforo
  //Light pins configurations
  pinMode(Semaforo1Verde, OUTPUT);
  pinMode(Semaforo1Amarillo, OUTPUT);
  pinMode(Semaforo1Rojo, OUTPUT);
  pinMode(Semaforo2Verde, OUTPUT);
  pinMode(Semaforo2Amarillo, OUTPUT);
  pinMode(Semaforo2Rojo, OUTPUT);
  /*Configurando el pin de emergencia
    Se configura como entrada
    Emergency pin configuration
    as input
    */
  pinMode(PinEmergencia,INPUT);
}

//Inicio del programa
//Main program
void loop()
{
  /*Asina el valor del reloj (millis()) a una variable 
    llamada ms 
    Takes the time in ms variable
  */
  unsigned long ms=millis();
  /*Cambio de tiempo desde la última ejecución
    Takes the change in the time of last execution
  */
  unsigned long Dt=ms-milisegundos;
  
  /* Registra si se pulsa el boton de emergencia
     If the emergency button is pulsed
  */
  int EstadoPinActivacion=digitalRead(PinEmergencia);
  /* Si está presionado el boton de emergencia registra dicho cambio
     If is pulsed the emergency button chages of state
  */
  if(EstadoActivacion!=EstadoPinActivacion){
    /*Decir que hay cambio de estado
      Occurs a change of state
    */
    CambioEstado=1;
  }
  /*En caso de que no hay cambio de estado
    If the emergency button is not pressed
  */
  else{
    /*Decir que no hay cambio de estado
      The state is the same as before
    */
    CambioEstado=0;
  }
  /*Si se ha cambiado de estado
    If there is a change of state
  */
  if(CambioEstado==1){
    /*Actualizar el estado
      The state is actualized
    */
    EstadoActivacion=EstadoPinActivacion;
    /* En caso de que se este inicializando el botón de emergencia:
       In case of the emergency button state is initializing
    */
    if(EstadoActivacion==1){
      /*Tomar el tiempo en que inicio la activacion
        Time is taken when the button is pressed
      */
      TiempoActivacion=millis();
    }
  }
  
  /*Si se ha activado el botón de emergencia y no hay cambio de estado
    The emergency button is pressed and there is not a change of state
  */
  if(EstadoActivacion==1&&!CambioEstado){
    /*Pedir tiempo actual
      Takes actual time
    */
    unsigned long milis=millis();
    /*Medir si han pasado .5 segundos
      If .5 seconds has passed
    */
    if((milis-TiempoActivacion)>=500){
      /*Cambiar el valor de emergencia
        Changes emergency state
      */
      Emergencia=!Emergencia;
      /*Reinicializa las variables que miden el tiempo
        Reinitializing the time variables
      */
      TiempoActivacion=ms;
      milisegundos=millis();
    }
  
  }
  
  
  /*Inicia ciclo normal
    Normal cycle 
  */
  
  /* Si no hay emergencia*/
  /* If there is not emergency */
  if(!Emergencia){
    /*Primer estado
      1s state
    */
  if(Dt<=5000){
    EstadoS1VLed=HIGH;
    EstadoS1ALed=LOW;
    EstadoS1RLed=LOW;
    EstadoS2VLed=LOW;
    EstadoS2ALed=LOW;
    EstadoS2RLed=HIGH;
    digitalWrite(Semaforo1Verde,EstadoS1VLed);
    digitalWrite(Semaforo1Amarillo,EstadoS1ALed);
    digitalWrite(Semaforo1Rojo,EstadoS1RLed);
    digitalWrite(Semaforo2Verde,EstadoS2VLed);
    digitalWrite(Semaforo2Amarillo,EstadoS2ALed);
    digitalWrite(Semaforo2Rojo,EstadoS2RLed);
  }
    /*Segundo estado
      2nd state
    */
  if(Dt>=5000&&Dt<=5500){
    EstadoS1VLed=LOW;
    digitalWrite(Semaforo1Verde,EstadoS1VLed);
  }
    /*Tercer estado
      3rd state
    */
  if(Dt>=5500&&Dt<=6500){
    EstadoS1VLed=HIGH;
    digitalWrite(Semaforo1Verde,EstadoS1VLed);
  }
    /*Cuarto estado
      4th state
    */
  if(Dt>=6500&&Dt<=7000){
    EstadoS1VLed=LOW;
    digitalWrite(Semaforo1Verde,EstadoS1VLed);
  }  
    /*Quinto estado
      5th state
    */
  if(Dt>=7000&&Dt<=7500){
    EstadoS1VLed=HIGH;
    digitalWrite(Semaforo1Verde,EstadoS1VLed);
  }
    /*Sexto estado
      6th state
    */
  if(Dt>=7500&&Dt<=9000){
    EstadoS1VLed=LOW;
    EstadoS1ALed=HIGH;
    digitalWrite(Semaforo1Verde,EstadoS1VLed);
    digitalWrite(Semaforo1Amarillo,EstadoS1ALed);
  }
    /*Seven estado
      7th state
    */
  if(Dt>=9000&&Dt<=12000){
    EstadoS1ALed=LOW;
    EstadoS1RLed=HIGH;
    EstadoS2VLed=HIGH;
    EstadoS2RLed=LOW;
    digitalWrite(Semaforo1Amarillo,EstadoS1ALed);
    digitalWrite(Semaforo1Rojo,EstadoS1RLed);
    digitalWrite(Semaforo2Verde,EstadoS2VLed);
    digitalWrite(Semaforo2Rojo,EstadoS2RLed);
  }
    /*Octavo estado
      8th state
    */
  if(Dt>=12000&&Dt<=12500){
    EstadoS2VLed=LOW;
    digitalWrite(Semaforo2Verde,EstadoS2VLed);
  }
    /*Noveno estado
      9th state
    */
  if(Dt>=12500&&Dt<=13500){
    EstadoS2VLed=HIGH;
    digitalWrite(Semaforo2Verde,EstadoS2VLed);
  }
    /*Decimo estado
      10th state
    */
  if(Dt>=13500&&Dt<=14000){
    EstadoS2VLed=LOW;
    digitalWrite(Semaforo2Verde,EstadoS2VLed);
  }  
    /*Undecimo estado
      1th state
    */
  if(Dt>=14000&&Dt<=14500){
    EstadoS2VLed=HIGH;
    digitalWrite(Semaforo2Verde,EstadoS2VLed);
  }
    /*Doceavo estado
      12th state
    */
  if(Dt>=14500&&Dt<=16000){
    EstadoS2VLed=LOW;
    EstadoS2ALed=HIGH;
    digitalWrite(Semaforo2Verde,EstadoS2VLed);
    digitalWrite(Semaforo2Amarillo,EstadoS2ALed);
  }
  
  /*Estado final
    Final state
  */
  if(Dt>=16000){
    EstadoS1VLed=HIGH;
    EstadoS1ALed=LOW;
    EstadoS1RLed=LOW;
    EstadoS2VLed=LOW;
    EstadoS2ALed=LOW;
    EstadoS2RLed=HIGH;
    digitalWrite(Semaforo1Verde,EstadoS1VLed);
    digitalWrite(Semaforo1Amarillo,EstadoS1ALed);
    digitalWrite(Semaforo1Rojo,EstadoS1RLed);
    digitalWrite(Semaforo2Verde,EstadoS2VLed);
    digitalWrite(Semaforo2Amarillo,EstadoS2ALed);
    digitalWrite(Semaforo2Rojo,EstadoS2RLed);
    milisegundos=millis();  
  }
   
  }
 
  /*Cuando se ha activado la emergencia
    When the emergency state is activated
  */
   else{
     
    if(Dt<=1000){
    EstadoS1VLed=HIGH;
    EstadoS1ALed=HIGH;
    EstadoS1RLed=HIGH;
    EstadoS2VLed=HIGH;
    EstadoS2ALed=HIGH;
    EstadoS2RLed=HIGH;
    digitalWrite(Semaforo1Verde,EstadoS1VLed);
    digitalWrite(Semaforo1Amarillo,EstadoS1ALed);
    digitalWrite(Semaforo1Rojo,EstadoS1RLed);
    digitalWrite(Semaforo2Verde,EstadoS2VLed);
    digitalWrite(Semaforo2Amarillo,EstadoS2ALed);
    digitalWrite(Semaforo2Rojo,EstadoS2RLed);
    }
     
    if(Dt>=1000&&Dt<=2000){
    EstadoS1VLed=LOW;
    EstadoS1ALed=LOW;
    EstadoS1RLed=LOW;
    EstadoS2VLed=LOW;
    EstadoS2ALed=LOW;
    EstadoS2RLed=LOW;
    digitalWrite(Semaforo1Verde,EstadoS1VLed);
    digitalWrite(Semaforo1Amarillo,EstadoS1ALed);
    digitalWrite(Semaforo1Rojo,EstadoS1RLed);
    digitalWrite(Semaforo2Verde,EstadoS2VLed);
    digitalWrite(Semaforo2Amarillo,EstadoS2ALed);
    digitalWrite(Semaforo2Rojo,EstadoS2RLed);
    }
     
     if(Dt>2000){
       milisegundos=millis();
     
     }
  
   }
   
   
}

