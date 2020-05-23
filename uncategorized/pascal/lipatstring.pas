const
  abjad='ABCDEFGHIJKLMNOPQRSTUVWXYZ';
  angka='0123456789';
  kurung='()';

var
  k,n,slot,l,r,i:integer;
  input:string;
  arr:array[1..10000] of char;

procedure f(k:integer);
  var
    l,r,i,j,k0,int:integer;
    num,kali:longint;
    temp:array[1..10] of integer;

  begin
    if pos(input[k],abjad)>0 then
      begin
        inc(slot);
        arr[slot]:=input[k];
      end
    else if pos(input[k],angka)>0 then
      begin
        for i:=1 to 10 do temp[i]:=0;
        i:=0;
        //dec(k);
        while pos(input[k],angka)>0 do
          begin
            inc(i);
            temp[i]:=ord(input[k])-48;
            inc(k);
          end;
        num:=0;
        kali:=1;
        for int:=i downto 1 do
          begin
            num:=num+kali*temp[int];
            kali:=kali*10;
          end;
        if num>0 then
          begin
            l:=1;
            r:=0;
            k0:=k;
            while l<>r do
              begin
                inc(k);
                if input[k]='(' then inc(l)
                  else if input[k]=')' then inc(r);
              end;
            for i:=1 to num do
              begin
                j:=k0;
                while j<=k do
                  begin
                    if pos(input[j],angka)>0 then
                      begin
                        f(j);
                        while pos(input[j],kurung)=0 do inc(j);
                        inc(j);
                        l:=1;
                        r:=0;
                        while l<>r do
                          begin
                            inc(j);
                            if input[j]='(' then inc(l)
                              else if input[j]=')' then inc(r);
                          end;
                      end
                    else
                      begin
                        f(j);
                        inc(j);
                      end;
                  end;

              end;
          end;
      end;
  end;

begin
  readln(input);
  k:=0;
  n:=length(input);
  slot:=0;
  while k<n do
    begin
      inc(k);
      f(k);
      if pos(input[k],angka)>0 then
        begin
          while pos(input[k],kurung)>0 do inc(k);
          inc(k);
          l:=1;
          r:=0;
          while l<>r do
            begin
              inc(k);
              if input[k]='(' then inc(l)
                else if input[k]=')' then inc(r);
            end;
        end;
    end;
  for i:=1 to slot do write(arr[i]);
  writeln;
end.
