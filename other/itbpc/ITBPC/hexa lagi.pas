var
  n,hasil,i,xmax,xmin,ymax,ymin,i_xmax,i_xmin,i_ymax,i_ymin,x_ul,i_x_ul,x_ur,i_x_ur,x_bl,i_x_bl,x_br,i_x_br,y_ul,i_y_ul,y_ur,i_y_ur,y_bl,i_y_bl,y_br,i_y_br:integer;
  x,y,int1:array[1..15] of integer;
  ylineul,ylineur,ylinebl,ylinebr:real;
  konkav,ul,ur,bl,br:boolean;

begin
  readln(n);
  for i:=1 to n do readln(x[i],y[i]);
  hasil:=0;
  for int1[1]:=1 to (n-5) do
    for int1[2]:=(int1[1]+1) to (n-4) do
      for int1[3]:=(int1[2]+1) to (n-3) do
        for int1[4]:=(int1[3]+1) to (n-2) do
          for int1[5]:=(int1[4]+1) to (n-1) do
            for int1[6]:=(int1[5]+1) to n do
              begin
                konkav:=false;

                //finding maximum value of x//
                xmax:=-1000;
                for i:=1 to 6 do
                  if x[int1[i]]>xmax then
                    begin
                      xmax:=x[int1[i]];
                      i_xmax:=int1[i];
                    end;

                //finding minimum value of x//
                xmin:=1000;
                for i:=1 to 6 do
                  if x[int1[i]]<xmin then
                    begin
                      xmin:=x[int1[i]];
                      i_xmin:=int1[i];
                    end;

                //finding maximum value of y//
                ymax:=-1000;
                for i:=1 to 6 do
                  if y[int1[i]]>ymax then
                    begin
                      ymax:=y[int1[i]];
                      i_ymax:=int1[i];
                    end;

                //finding minimum value of y//
                ymin:=1000;
                for i:=1 to 6 do
                  if y[int1[i]]<ymin then
                    begin
                      ymin:=y[int1[i]];
                      i_ymin:=int1[i];
                    end;

                //finding up-left bound of the hexagon//
                x_ul:=1000;
                for i:=1 to 6 do
                  if y[int1[i]]=ymax then
                    if x[int1[i]]<x_ul then
                      begin
                        x_ul:=x[int1[i]];
                        i_x_ul:=int1[i];
                      end;
                y_ul:=-1000;
                for i:=1 to 6 do
                  if x[int1[i]]=xmin then
                    if y[int1[i]]>y_ul then
                      begin
                        y_ul:=y[int1[i]];
                        i_y_ul:=int1[i];
                      end;

                //finding up-right bound of the hexagon//
                x_ur:=-1000;
                for i:=1 to 6 do
                  if y[int1[i]]=ymax then
                    if x[int1[i]]>x_ur then
                      begin
                        x_ur:=x[int1[i]];
                        i_x_ur:=int1[i];
                      end;
                y_ur:=-1000;
                for i:=1 to 6 do
                  if x[int1[i]]=xmax then
                    if y[int1[i]]>y_ur then
                      begin
                        y_ur:=y[int1[i]];
                        i_y_ur:=int1[i];
                      end;

                //finding bottom-left bound of the hexagon//
                x_bl:=1000;
                for i:=1 to 6 do
                  if y[int1[i]]=ymin then
                    if x[int1[i]]<x_bl then
                      begin
                        x_bl:=x[int1[i]];
                        i_x_bl:=int1[i];
                      end;
                y_bl:=1000;
                for i:=1 to 6 do
                  if x[int1[i]]=xmin then
                    if y[int1[i]]<y_bl then
                      begin
                        y_bl:=y[int1[i]];
                        i_y_bl:=int1[i];
                      end;

                //finding bottom-right bound of the hexagon//
                x_br:=-1000;
                for i:=1 to 6 do
                  if y[int1[i]]=ymin then
                    if x[int1[i]]>x_br then
                      begin
                        x_br:=x[int1[i]];
                        i_x_br:=int1[i];
                      end;
                y_br:=1000;
                for i:=1 to 6 do
                  if x[int1[i]]=xmax then
                    if y[int1[i]]<y_br then
                      begin
                        y_br:=y[int1[i]];
                        i_y_br:=int1[i];
                      end;

                //checking the convexity//


                for i:=1 to 6 do
                  begin

                    if not(i_x_ul=i_y_ul) then
                      begin
                        if not(i_x_ul=i) and not(i_y_ul=i) then
                          begin
                            ylineul:=(((x[int1[i]]-xmin)*(ymax-y_ul))/(x_ul-xmin))+y_ul;
                            if ylineul>=y[int1[i]] then ul:=true;
                          end
                        else ul:=false;
                      end;

                    if not(i_x_ur=i_y_ur) then
                      begin
                        if not(i_x_ur=i) and not(i_y_ur=i) then
                          begin
                            ylineur:=(((x[int1[i]]-x_ur)*(y_ur-ymax))/(xmax-x_ur))+ymax;
                            if ylineur>=y[int1[i]] then ur:=true;
                          end
                        else ur:=false;
                      end;

                    if not(i_x_bl=i_y_bl) then
                      begin
                        if not(i_x_bl=i) and not(i_y_bl=i) then
                          begin
                            ylinebl:=(((x[int1[i]]-xmin)*(ymin-y_bl))/(x_bl-xmin))+y_bl;
                            if ylinebl<=y[int1[i]] then bl:=true;
                          end
                        else bl:=false;
                      end;

                    if not(i_x_br=i_y_br) then
                      begin
                        if not(i_x_br=i) and not(i_y_br=i) then
                          begin
                            ylinebr:=(((x[int1[i]]-x_br)*(y_br-ymin))/(xmax-x_br))+ymin;
                            if ylinebr<=y[int1[i]] then br:=true;
                            end
                        else br:=false;
                      end;

                    if (ul and ur and bl and br) then
                      begin
                        konkav:=true;
                        break;
                      end;

                  end;

                if not(konkav) then inc(hasil);
              end;
  writeln(hasil);
end.
