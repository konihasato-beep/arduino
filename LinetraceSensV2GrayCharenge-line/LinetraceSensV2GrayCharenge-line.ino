//MicrofanClcdPlus LineTrace Basic
#include <ClcdPlus.h>
// MD縺ｮpin險ｭ螳� ;MD1IN1->4, MD1IN2->5, MD2IN1->6, MD2IN2->7 

//Microfan ClcdPlus
ClcdPlus lcd;
int cnt;           // cnt縺ｯA/D螟画鋤蛟､逕ｨ縺ｮ螟画焚
int cntmid_shiro= 449;
int cntmid_kuro= 449;
int cntmid_hai=449;
int average_shiro=0;
int average_kuro=0;
int i=0;
int s=1000;
int g_count=0;
int mode=0;
// cntmid縺ｯ逋ｽ鮟偵�髢ｾ蛟､逕ｨ縺ｧ蛻晄悄蛟､繧�1024/2縺ｧ512縺ｫ莉ｮ險ｭ螳�
int motorwait=50;  //motorwait縺ｯ50ms繝ｭ繝懊ャ繝医�荳蝗槫虚菴懊ｒ邯咏ｶ壹☆繧九◆繧√�蠕�■譎る俣

void setup()
{
//繝�ず繧ｿ繝ｫI/Opin4567繧貞�蜉幄ｨｭ螳�
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
// 繧｢繝翫Ο繧ｰ0��5縺ｮA/D縺ｯ閾ｪ蜍慕噪縺ｫ蜈･蜉帙↓險ｭ螳壹＆繧後ｋ 
  lcd.begin(16, 2);      // LCD蛻晄悄蛹�
  lcd.backLight(1) ;     // 繝舌ャ繧ｯ繝ｩ繧､繝育せ轣ｯ
  lcd.print("MF CLCD-PLUS Shield");
  lcd.setCursor(0,1) ;   // 繧ｫ繝ｼ繧ｽ繝ｫ繧�0,1縺ｫ遘ｻ蜍�
  lcd.print("LineTraceBasicV2");
  lcd.beep(1);  delay(50);   lcd.beep(0);  // 繝薙�繝励ｒ繝斐→魑ｴ繧峨☆
  delay(3000) ;lcd.clear();         // 3遘貞ｾ�▲縺ｦLCD繧ｯ繝ｪ繧｢
// 繧｢繝翫Ο繧ｰ0��5pin縺ｮA/D縺ｯ閾ｪ蜍慕噪縺ｫ蜈･蜉帙↓險ｭ螳壹＆繧後ｋ 
}

void loop()
{
  lcd.setCursor(0,1);  // 繧ｫ繝ｼ繧ｽ繝ｫ繧�0,1縺ｫ遘ｻ蜍�
  lcd.print( "setSHIRO &HitSW1  " );
  while( (lcd.sw1()) == 0 ){  //sw1縺梧款縺輔ｌ繧九∪縺ｧ郢ｰ繧願ｿ斐＠
        cnt =analogRead(0);   // A/D螟画鋤AD0繝昴�繝医�蛟､繧団nt縺ｫ莉｣蜈･
        lcd.setCursor(0,0);  
        lcd.print( "ch0=");
        lcd.print(cnt);       // cnt縺ｮ陦ｨ遉ｺ
        lcd.print("  ");
        cntmid_shiro=cnt;           // cntmid縺ｫcnt繧偵さ繝斐�
        delay( 200 );         // 0.2遘貞ｮ溯｡悟●豁｢
  }
  delay( 800 );

  
  lcd.setCursor(0,1);        // 繧ｫ繝ｼ繧ｽ繝ｫ繧�0,1縺ｫ遘ｻ蜍�
  lcd.print( "setKURO &HitSW1  " );
  while( (lcd.sw1()) == 0 ){  //sw1縺梧款縺輔ｌ繧九∪縺ｧ郢ｰ繧願ｿ斐＠
        cnt =analogRead(0);   // A/D螟画鋤AD0繝昴�繝医�蛟､繧団nt縺ｫ莉｣蜈･ 
        lcd.setCursor(0,0);   // 繧ｫ繝ｼ繧ｽ繝ｫ繧�0,0縺ｫ遘ｻ蜍�
        lcd.print( "ch0=");
        lcd.print(cnt);       // cnt縺ｮ陦ｨ遉ｺ
        lcd.print("  ");
        cntmid_kuro=cnt; 
        delay( 200 );         // 0.2遘貞ｮ溯｡悟●豁｢
  }
  delay( 800 );


 lcd.setCursor(0,1);  // 繧ｫ繝ｼ繧ｽ繝ｫ繧�0,1縺ｫ遘ｻ蜍�
  lcd.print( "setGRAY &HitSW1  " );
  while( (lcd.sw1()) == 0 ){  //sw1縺梧款縺輔ｌ繧九∪縺ｧ郢ｰ繧願ｿ斐＠
        cnt =analogRead(0);   // A/D螟画鋤AD0繝昴�繝医�蛟､繧団nt縺ｫ莉｣蜈･
        lcd.setCursor(0,0);  
        lcd.print( "ch0=");
        lcd.print(cnt);       // cnt縺ｮ陦ｨ遉ｺ
        lcd.print("  ");
        cntmid_hai=cnt;           // cntmid縺ｫcnt繧偵さ繝斐�
        delay( 200 );         // 0.2遘貞ｮ溯｡悟●豁｢
  }
  delay( 800 );
    
  lcd.clear();         // LCD繧ｯ繝ｪ繧｢
  lcd.setCursor(0,0);   // 繧ｫ繝ｼ繧ｽ繝ｫ繧�0,0縺ｫ遘ｻ蜍�
  lcd.print("SHIRO");
  lcd.print(cntmid_shiro);    // 逋ｽ縺ｮ譎ゅ�A/D蛟､縺ｮ陦ｨ遉ｺ
  lcd.print(" KURO");
  lcd.print(cntmid_kuro);
     
  lcd.setCursor(0,1);
  lcd.print(" GRAY");
  lcd.print(cntmid_hai);
  lcd.print(" NEXTsw3");
  while( (lcd.sw3()) == 0 ){  // sw3縺梧款縺輔ｌ繧九∪縺ｧ郢ｰ繧願ｿ斐＠
     delay(20);               // 0.02遘貞ｾ�▽
  }
  delay( 800 );

  average_shiro=(cntmid_shiro + cntmid_hai)/2; 
  average_kuro=(cntmid_kuro + cntmid_hai)/2;// cntmid縺ｯ逋ｽ鮟偵�蟷ｳ蝮�ｼ磯明蛟､��

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("H_shiro");
  lcd.print(average_shiro); 
  lcd.setCursor(0,1);// 逋ｽ鮟貞､縺ｮ蟷ｳ蝮�ｼ磯明蛟､�営ntmid陦ｨ遉ｺ
  lcd.print("H_kuro");
  lcd.print(average_kuro);
  lcd.print("NEXTSW3."); 
  while( (lcd.sw3()) == 0 ){  // sw3縺梧款縺輔ｌ繧九∪縺ｧ郢ｰ繧願ｿ斐＠
     delay(20);               // 0.02遘貞ｾ�▽
  }
  delay( 800 );

  lcd.clear();





  
  lcd.setCursor(0,1);  // 繧ｫ繝ｼ繧ｽ繝ｫ繧�0,1縺ｫ遘ｻ蜍�
  lcd.print("Press SW1 START ");
//'sw1縺梧款縺輔ｌ繧九∪縺ｧ郢ｰ繧願ｿ斐＠
  while( (lcd.sw1()) == 0 ){  //sw1縺梧款縺輔ｌ繧九∪縺ｧ郢ｰ繧願ｿ斐＠
        cnt = analogRead(0);  // A/D螟画鋤AD0繝昴�繝医�蛟､繧団nt縺ｫ莉｣蜈･
        lcd.setCursor(0,0);   // 繧ｫ繝ｼ繧ｽ繝ｫ繧�0,0縺ｫ遘ｻ蜍�
        lcd.print( "ch0=");
        lcd.print(cnt);       // cnt縺ｮ陦ｨ遉ｺ
        lcd.print("  ");
        delay( 200 );         // 0.2遘貞ｮ溯｡悟●豁｢
  }
  delay( 800 );               // 0.8遘貞ｾ�▽�後せ繧､繝�メ繧帝屬縺吶∪縺ｧ縺ｮ蠕�■譎る俣
//'sw1縺梧款縺輔ｌ縺溘ｉ0.8遘貞ｾ�▲縺ｦ繧ｹ繧ｿ繝ｼ繝�
  lcd.clear();
  while(1){       // 莉･荳九ｒ辟｡髯千ｹｰ繧願ｿ斐＠ 
        cnt = analogRead(0);  // A/D螟画鋤AD0繝昴�繝医�蛟､繧団nt縺ｫ莉｣蜈･ 
        lcd.setCursor(0,0);   // 繧ｫ繝ｼ繧ｽ繝ｫ繧�0,0縺ｫ遘ｻ蜍�
        lcd.print("ch0=");
        lcd.print(cnt);  
        lcd.print("i=");
        lcd.print(i);   // cnt縺ｮ陦ｨ遉ｺ
        lcd.print("   ");    
        lcd.setCursor(0,1);   // 繧ｫ繝ｼ繧ｽ繝ｫ繧�0,1縺ｫ遘ｻ蜍�
        
        if( average_shiro > cnt ){ //白
          mode=1;
          if( g_count == 1 ){ //1のとき前進(灰色一回検知で前進)
                 
                  s=s+1;
                  digitalWrite(4,LOW );   //蟾ｦ蝗櫁ｻ｢ 0001
                  digitalWrite(5, LOW);
                  digitalWrite(6, HIGH);
                  digitalWrite(7, LOW);   
                  lcd.setCursor(0,1); 
                  lcd.print("fow1 ");
                  lcd.print("g=");
                  lcd.print(g_count);
                  delay(motorwait);  
                  
                  digitalWrite(4,HIGH );   //蟾ｦ蝗櫁ｻ｢ 0001
                  digitalWrite(5, LOW);
                  digitalWrite(6, LOW);
                  digitalWrite(7, LOW);
                  lcd.setCursor(0,1);
                  lcd.print("fow2 ");
                  lcd.print("g=");
                  lcd.print(g_count);
                  delay(motorwait); 

                  digitalWrite(4,HIGH );   //蟾ｦ蝗櫁ｻ｢ 0001
                  digitalWrite(5, LOW);
                  digitalWrite(6, LOW);
                  digitalWrite(7, LOW);
                  lcd.setCursor(0,1);
                  lcd.print("fow2 ");
                  lcd.print("g=");
                  lcd.print(g_count);
                  delay(motorwait); 
             }
            else{
                s=s+1;/////left
                digitalWrite(4,HIGH );   
                digitalWrite(5, LOW);
                digitalWrite(6, LOW);
                digitalWrite(7, LOW);    
                lcd.setCursor(0,1);
                lcd.print("left ");
                lcd.print("g=");
                lcd.print(g_count);
                i=0;
                delay(motorwait);  
             }
        }

        else if( average_kuro < cnt ){ //kuro
            mode=0;
            digitalWrite(4,LOW );   //蟾ｦ蝗櫁ｻ｢ 0001
            digitalWrite(5, LOW);
            digitalWrite(6, HIGH);
            digitalWrite(7, LOW);    
            lcd.setCursor(0,1);
            lcd.print("right");
            lcd.print("g=");
            lcd.print(g_count);
            i=0;
            delay(motorwait);
         }
         else{
            i=i+1;
            if(i>100){//gray
              if(mode!=2)//継続じゃない
                  g_count= g_count+1;
               mode=2;
               if( g_count > 2 ){ //3になったとき
                  //s=s+1;
                  digitalWrite(4,LOW );   //蟾ｦ蝗櫁ｻ｢ 0001
                  digitalWrite(5, LOW);
                  digitalWrite(6, LOW);
                  digitalWrite(7, LOW);   
                  lcd.setCursor(0,1); 
                  lcd.print("stop ");
               // i=0;
                  lcd.print("g=");
                  lcd.print(g_count);
                  delay(motorwait);  
             }
             else{   //１，２のとき
              digitalWrite(4, HIGH);    //蜿ｳ蝗櫁ｻ｢ 0100
              digitalWrite(5,LOW );
              digitalWrite(6,LOW);
              digitalWrite(7, LOW);   
              lcd.setCursor(0,1);
              lcd.print("fow1 ");
              lcd.print("g=");
              lcd.print(g_count);
//             // i=0;
             // lcd.print("s=");
             // lcd.print(s);
              delay(motorwait);
              digitalWrite(4, LOW);    //蜿ｳ蝗櫁ｻ｢ 0100
              digitalWrite(5,LOW );
              digitalWrite(6,HIGH);
              digitalWrite(7, LOW); 
              lcd.setCursor(0,1);
              lcd.print("fow2 ");
              lcd.print("g=");
              lcd.print(g_count);
              delay(motorwait);
              }
           }
           
        }
    }
}
