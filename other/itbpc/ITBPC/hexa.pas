var
  n,x1,x2,x3,x4,x5,x6,hasil:integer;
  i,xmax,xmin,ymax,ymin,i_xmax,i_xmin,i_ymax,i_ymin:integer;
  x,y,int1,int2:array[1..15] of integer;
  konkav:boolean;

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
                for int2[1]:=1 to 3 do
                  begin
                  for int2[2]:=(int2[1]+1) to 4 do
                    begin
                    for int2[3]:=(int2[2]+1) to 5 do
                      begin
                      for int2[4]:=(int2[3]+1) to 6 do
                        begin
                          xmax:=-1000;
                          i_xmax:=0;
                          for i:=1 to 4 do
                            if x[int1[int2[i]]]>xmax then
                              begin
                                xmax:=x[int1[int2[i]]];
                                i_xmax:=int1[int2[i]];
                              end;
                          xmin:=1000;
                          i_xmin:=0;
                          for i:=1 to 4 do
                            if x[int1[int2[i]]]<xmin then
                              begin
                                xmin:=x[int1[int2[i]]];
                                i_xmin:=int1[int2[i]];
                              end;
                          ymax:=-1000;
                          i_ymax:=0;
                          for i:=1 to 4 do
                            if y[int1[int2[i]]]>ymax then
                              begin
                                ymax:=y[int1[int2[i]]];
                                i_ymax:=int1[int2[i]];
                              end;
                          ymin:=1000;
                          i_ymin:=0;
                          for i:=1 to 4 do
                            if y[int1[int2[i]]]<ymin then
                              begin
                                ymin:=y[int1[int2[i]]];
                                i_ymin:=int1[int2[i]];
                              end;
                          if (i_xmax=i_ymin) or (i_xmax=i_ymax) or (i_xmin=i_ymin) or (i_xmin=i_ymax) then
                            begin
                              konkav:=true;
                            end;

                          if konkav then break;
                        end;
                      if konkav then break;
                      end;
                    if konkav then break;
                    end;
                  if konkav then break;
                  end;
                if not(konkav) then inc(hasil);
              end;
  writeln(hasil);
end.
