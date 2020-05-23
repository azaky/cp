var
  r,c,n,i,j,k,len:longint;
  space:char;
  s,temp,reflect:string;
  found:boolean;
  a:array[0..101,0..101] of char;

function check:boolean;
  begin
    if found then exit(true);
    if (temp<>s) and (temp<>reflect) then exit(false);
    found:=true; exit(true);
  end;

function min(a,b:longint):longint;
  begin
    if a<b then exit(a)
      else exit(b);
  end;

begin
  readln(r,c);
  for i:=1 to r do
    for j:=1 to c do
      if j=c then readln(a[i,j])
        else read(a[i,j],space);
  readln(n);
  for k:=1 to n do
    begin
      readln(s); write(s,' ');
      len:=length(s);
      reflect:='';
      for i:=len downto 1 do reflect:=reflect+s[i];
      found:=false;
      //horisontal
      if len<=c then
        for i:=1 to r do
          begin
            temp:='';
            for j:=1 to len do temp:=temp+a[i,j];
            for j:=len+1 to c+1 do
              begin
                if check then break;
                delete(temp,1,1);
                temp:=temp+a[i,j];
              end;
          end;
      if found then
        begin
          writeln('Y');
          continue;
        end;
      //vertikal
      if len<=r then
        for i:=1 to c do
          begin
            //kiri-kanan
            temp:='';
            for j:=1 to len do temp:=temp+a[j,i];
            for j:=len+1 to r+1 do
              begin
                if check then break;
                delete(temp,1,1);
                temp:=temp+a[j,i];
              end;
          end;
      if found then
        begin
          writeln('Y');
          continue;
        end;
      //diagonal
      if (len<=r) and (len<=c) then
        begin
          //kiri atas<->kanan bawah
          for i:=1 to r do
            begin
              if r-i+1<len then break;
              temp:='';
              for j:=1 to len do temp:=temp+a[i+j-1,j];
              for j:=len+1 to min(c+1,r-i+2) do
                begin
                  if check then break;
                  delete(temp,1,1);
                  temp:=temp+a[i+j-1,j];
                end;
            end;
          for i:=2 to c do
            begin
              if c-i+1<len then break;
              temp:='';
              for j:=1 to len do temp:=temp+a[j,i+j-1];
              for j:=len+1 to min(r+1,c-i+2) do
                begin
                  if check then break;
                  delete(temp,1,1);
                  temp:=temp+a[j,i+j-1];
                end;
            end;
          //kiri bawah<->kanan atas
          for i:=r downto 1 do
            begin
              if i<len then break;
              temp:='';
              for j:=1 to len do temp:=temp+a[i-j+1,j];
              for j:=len+1 to min(c+1,i+1) do
                begin
                  if check then break;
                  delete(temp,1,1);
                  temp:=temp+a[i-j+1,j];
                end;
            end;
          for i:=2 to c do
            begin
              if c-i+1<len then break;
              temp:='';
              for j:=1 to len do temp:=temp+a[c-j+1,i+j-1];
              for j:=len+1 to min(r+1,c-i+2) do
                begin
                  if check then break;
                  delete(temp,1,1);
                  temp:=temp+a[c-j+1,i+j-1];
                end;
            end;
        end;

      if found then writeln('Y')
        else writeln('T');
    end;
end.
