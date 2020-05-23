var
  n,hasil,i,int1,int2,int3,int4,int5,int6,xmax,xmin,ymax,ymin,i_xmax,i_xmin,i_ymax,i_ymin,x_ul,i_x_ul,x_ur,i_x_ur,x_bl,i_x_bl,x_br,i_x_br,y_ul,i_y_ul,y_ur,i_y_ur,y_bl,i_y_bl,y_br,i_y_br:integer;
  x,y,int:array[1..15] of integer;
  ylineul,ylineur,ylinebl,ylinebr:real;
  konkav,ul,ur,bl,br:boolean;

function yline(x,x1,y1,x2,y2:integer):real;

  begin
    yline:=(((x-x1)*(y2-y1))/(x2-x1))+y1;
  end;

begin
  readln(n);
  for i:=1 to n do readln(x[i],y[i]);
  hasil:=0;
  for int1:=1 to (n-5) do
    for int2:=(int1+1) to (n-4) do
      for int3:=(int2+1) to (n-3) do
        for int4:=(int3+1) to (n-2) do
          for int5:=(int4+1) to (n-1) do
            for int6:=(int5+1) to n do
              begin

                int[1]:=int1;
                int[2]:=int2;
                int[3]:=int3;
                int[4]:=int4;
                int[5]:=int5;
                int[6]:=int6;

                //finding maximum value of x//
                xmax:=-1000;
                for i:=1 to 6 do
                  if x[int[i]]>xmax then
                    begin
                      xmax:=x[int[i]];
                      i_xmax:=int[i];
                    end;

                //finding minimum value of x//
                xmin:=1000;
                for i:=1 to 6 do
                  if x[int[i]]<xmin then
                    begin
                      xmin:=x[int[i]];
                      i_xmin:=int[i];
                    end;

                //finding maximum value of y//
                ymax:=-1000;
                for i:=1 to 6 do
                  if y[int[i]]>ymax then
                    begin
                      ymax:=y[int[i]];
                      i_ymax:=int[i];
                    end;

                //finding minimum value of y//
                ymin:=1000;
                for i:=1 to 6 do
                  if y[int[i]]<ymin then
                    begin
                      ymin:=y[int[i]];
                      i_ymin:=int[i];
                    end;

                //finding up-left bound of the hexagon//
                x_ul:=1000;
                for i:=1 to 6 do
                  if y[int[i]]=ymax then
                    if x[int[i]]<x_ul then
                      begin
                        x_ul:=x[int[i]];
                        i_x_ul:=int[i];
                      end;
                y_ul:=-1000;
                for i:=1 to 6 do
                  if x[int[i]]=xmin then
                    if y[int[i]]>y_ul then
                      begin
                        y_ul:=y[int[i]];
                        i_y_ul:=int[i];
                      end;

                //finding up-right bound of the hexagon//
                x_ur:=-1000;
                for i:=1 to 6 do
                  if y[int[i]]=ymax then
                    if x[int[i]]>x_ur then
                      begin
                        x_ur:=x[int[i]];
                        i_x_ur:=int[i];
                      end;
                y_ur:=-1000;
                for i:=1 to 6 do
                  if x[int[i]]=xmax then
                    if y[int[i]]>y_ur then
                      begin
                        y_ur:=y[int[i]];
                        i_y_ur:=int[i];
                      end;

                //finding bottom-left bound of the hexagon//
                x_bl:=1000;
                for i:=1 to 6 do
                  if y[int[i]]=ymin then
                    if x[int[i]]<x_bl then
                      begin
                        x_bl:=x[int[i]];
                        i_x_bl:=int[i];
                      end;
                y_bl:=1000;
                for i:=1 to 6 do
                  if x[int[i]]=xmin then
                    if y[int[i]]<y_bl then
                      begin
                        y_bl:=y[int[i]];
                        i_y_bl:=int[i];
                      end;

                //finding bottom-right bound of the hexagon//
                x_br:=-1000;
                for i:=1 to 6 do
                  if y[int[i]]=ymin then
                    if x[int[i]]>x_br then
                      begin
                        x_br:=x[int[i]];
                        i_x_br:=int[i];
                      end;
                y_br:=1000;
                for i:=1 to 6 do
                  if x[int[i]]=xmax then
                    if y[int[i]]<y_br then
                      begin
                        y_br:=y[int[i]];
                        i_y_br:=int[i];
                      end;

                //checking the convexity//

                for i:=1 to 6 do
                  begin

                    ul:=true;
                    ur:=true;
                    bl:=true;
                    br:=true;

                    if not(i_x_ul=int[i]) and not(i_x_ur=int[i]) and not(i_x_bl=int[i]) and not(i_x_br=int[i]) and not(i_y_ul=int[i]) and not(i_y_ur=int[i]) and not(i_y_bl=int[i]) and not(i_y_br=int[i]) then
                      begin

                        if not(x_ul=xmin) then
                          begin
                            ylineul:=yline(x[int[i]],xmin,y_ul,x_ul,ymax);
                            if ylineul>=y[int[i]] then ul:=true else ul:=false;
                          end;

                        if not(x_ur=xmax) then
                          begin
                            ylineur:=yline(x[int[i]],x_ur,ymax,xmax,y_ur);
                            if ylineur>=y[int[i]] then ur:=true else ur:=false;
                          end;

                        if not(x_bl=xmin) then
                          begin
                            ylinebl:=yline(x[int[i]],xmin,y_bl,x_bl,ymin);
                            if ylinebl<y[int[i]] then bl:=true else bl:=false;
                          end;

                        if not(x_br=xmax) then
                          begin
                            ylinebr:=yline(x[int[i]],x_br,ymin,xmax,y_br);
                            if ylinebr<=y[int[i]] then br:=true else br:=false;
                          end;

                      end
                    else
                      begin
                        ul:=false;
                        ur:=false;
                        bl:=false;
                        br:=false;
                      end;

                    if (ul and ur and bl and br) then
                      begin
                        konkav:=true;
                        break;
                      end
                    else konkav:=false;

                  end;

                if not(konkav) then inc(hasil);
              end;
  writeln(hasil);
end.
