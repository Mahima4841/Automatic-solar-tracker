# include < Servo .h >
 Servo azith , elev ;
 int currpos_hor =90;
 int currpos_ver =20;

 void setup () {
 pinMode ( A0 , INPUT ) ;
 pinMode ( A1 , INPUT ) ;
 pinMode ( A2 , INPUT ) ;
 pinMode ( A3 , INPUT ) ;
 azith . attach (3) ;
 elev . attach (4) ;
 Serial . begin (9600) ;
 }

 void loop () {
 int v1 = analogRead ( A0 ) ;
 int v2 = analogRead ( A1 ) ;
 int v3 = analogRead ( A2 ) ;
 int v4 = analogRead ( A3 ) ;
 Serial . print ( v1 ) ;
 Serial . print (’,’) ;
 Serial . print ( v2 ) ;
 Serial . print (’,’) ;
 Serial . print ( v3 ) ;
 Serial . print (’,’) ;
 Serial . println ( v4 ) ;
 currpos_hor +=(((( v4 + v2 ) /2) -(( v3 + v1 ) /2) ) /50) ;
 if( currpos_hor <=0)
 currpos_hor =0;
 else if( currpos_hor >=180)
 currpos_hor =180;
 currpos_ver +=(((( v1 + v2 ) /2) -(( v3 + v4 ) /2) ) /50) ;
 if( currpos_ver <=0)
 currpos_ver =0;
 else if( currpos_ver >=110)
 currpos_ver =110;
 azith . write ( currpos_hor ) ;
 elev . write ( currpos_ver ) ;
 delay (100) ;
 }
