/*Pines del semaforo 1
  Verde 3
  Amarillo 5
  Rojo 6
*/

int Semaforo1Verde=3;
int Semaforo1Amarillo=5;
int Semaforo1Rojo=6;



/*Pines del semaforo 2
  Verde 9
  Amarillo 10
  Rojo 11
*/
int Semaforo2Verde=9;
int Semaforo2Amarillo=10;
int Semaforo2Rojo=11;


//Estado del led Semaforo
int EstadoS1VLed=HIGH;
int EstadoS1ALed=LOW;
int EstadoS1RLed=LOW;
int EstadoS2VLed=LOW;
int EstadoS2ALed=LOW;
int EstadoS2RLed=HIGH;

/*Variable que medirá el tiempo*/
unsigned long milisegundos=0;

/*Para activar la emergencia*/
int Emergencia=0;
int EstadoActivacion=0;
int CambioEstado=0;
int TiempoActivacion=0;

/*Pin del sensor de emergencia*/
int PinEmergencia=2;


//Estado Inicial
void setup()
{
  //Configurando los pines del semaforo
  pinMode(Semaforo1Verde, OUTPUT);
  pinMode(Semaforo1Amarillo, OUTPUT);
  pinMode(Semaforo1Rojo, OUTPUT);
  pinMode(Semaforo2Verde, OUTPUT);
  pinMode(Semaforo2Amarillo, OUTPUT);
  pinMode(Semaforo2Rojo, OUTPUT);
  //Configurando el pin de emergencia
  pinMode(PinEmergencia,INPUT);
}

//Inicio del programa
void loop()
{
  //Asina el valor del reloj (millis()) a una variable 
  //llamada ms
  unsigned long ms=millis();
  //Cambio de tiempo 
  unsigned long Dt=ms-milisegundos;
  
  //Cambia el estado a emergencia
  
  int EstadoPinActivacion=digitalRead(PinEmergencia);
  //Si el pulsador cambio de estado 
  if(EstadoActivacion!=EstadoPinActivacion){
    //Decir que hay cambio de estado
    CambioEstado=1;
  }
  //En caso de que no hay cambio de estado
  else{
    //Decir que no hay cambio de estado
    CambioEstado=0;
  }
  //Si se ha cambiado de estado
  if(CambioEstado==1){
    //Actualizar el estado
    EstadoActivacion=EstadoPinActivacion;
    //Si se presionado el activador
    if(EstadoActivacion==1){
      //Tomar el tiempo en que inicio la activacion
      TiempoActivacion=millis();
    }
  }
  
  //Si se ha activado el pulsador de emergencia y no hay cambio de estado
  if(EstadoActivacion==1&&!CambioEstado){
    //Pedir tiempo actual
    unsigned long milis=millis();
    //Medir si han pasado 1 segundo
    if((milis-TiempoActivacion)>=500){
      //Cambiar el valor de emergencia
      Emergencia=!Emergencia;
      //Actualizar el tiempo de activación
      TiempoActivacion=ms;
      milisegundos=millis();
    }
  
  }
  
  
  //Inicia ciclo normal
  
  if(!Emergencia){
  //Termina el cambio de emergencia.
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
  if(Dt>=5000&&Dt<=5500){
    EstadoS1VLed=LOW;
    digitalWrite(Semaforo1Verde,EstadoS1VLed);
  }
  if(Dt>=5500&&Dt<=6500){
    EstadoS1VLed=HIGH;
    digitalWrite(Semaforo1Verde,EstadoS1VLed);
  }
  if(Dt>=6500&&Dt<=7000){
    EstadoS1VLed=LOW;
    digitalWrite(Semaforo1Verde,EstadoS1VLed);
  }  
  if(Dt>=7000&&Dt<=7500){
    EstadoS1VLed=HIGH;
    digitalWrite(Semaforo1Verde,EstadoS1VLed);
  }
  if(Dt>=7500&&Dt<=9000){
    EstadoS1VLed=LOW;
    EstadoS1ALed=HIGH;
    digitalWrite(Semaforo1Verde,EstadoS1VLed);
    digitalWrite(Semaforo1Amarillo,EstadoS1ALed);
  }
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
  if(Dt>=12000&&Dt<=12500){
    EstadoS2VLed=LOW;
    digitalWrite(Semaforo2Verde,EstadoS2VLed);
  }
  if(Dt>=12500&&Dt<=13500){
    EstadoS2VLed=HIGH;
    digitalWrite(Semaforo2Verde,EstadoS2VLed);
  }
  if(Dt>=13500&&Dt<=14000){
    EstadoS2VLed=LOW;
    digitalWrite(Semaforo2Verde,EstadoS2VLed);
  }  
  if(Dt>=14000&&Dt<=14500){
    EstadoS2VLed=HIGH;
    digitalWrite(Semaforo2Verde,EstadoS2VLed);
  }
  if(Dt>=14500&&Dt<=16000){
    EstadoS2VLed=LOW;
    EstadoS2ALed=HIGH;
    digitalWrite(Semaforo2Verde,EstadoS2VLed);
    digitalWrite(Semaforo2Amarillo,EstadoS2ALed);
  }
  
  
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

