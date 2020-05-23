var

procedure product(x:array of integer; nx,y:integer);
  var

  begin
    ny:=trunc(ln(y)/ln(10))+1;
    for i:=1 to ny do sum(temphasil,x,
  end;

procedure sum(x,y:array of integer; nx,ny:integer);
  var
    temp:string;
    sisa,temp1,temp2,s:integer;
    stat:boolean;

  begin
    if length(x)<length(y) then
      begin
        temp:=x;
        x:=y;
        y:=temp;
      end;
    stat:=true;
    n:=1;
    sisa:=0;
    while stat do
      begin
        if n>length(x) then
          begin
            temp1:=0;
            temp2:=0;
            stat:=false;
          end
        else if n>length(y) then
          begin
            val(x[length(x)+1-n],temp1);
            temp2:=0;
          end
        else
          begin
            val(x[length(x)+1-n],temp1);
            val(y[length(y)+1-n],temp2);
          end;
        s:=temp1+temp2+sisa;
        if s<10 then
          begin
            hasil[n]:=s;
            sisa:=0;
          end
        else
          begin
            hasil[n]:=s mod 10;
            sisa:=1;
          end;
        if n>length(x) then
          if s=0 then dec(n)
            else
          else inc(n);
      end;
  end;
