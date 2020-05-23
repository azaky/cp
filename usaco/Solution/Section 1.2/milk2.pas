{
ID: a_zaky01
PROG: milk2
LANG: PASCAL
}

var
  min,max,i,j,n,awal,akhir,maxmilk,maxidle,k,count:longint;
  stat:string;
  milk:array[1..1000000] of boolean;
  fin,fout:text;

begin
  assign(fin,'milk2.in');
  assign(fout,'milk2.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  min:=0;
  max:=0;
  for i:=1 to n do
    begin
      readln(fin,awal,akhir);
      for j:=awal to (akhir-1) do milk[j]:=true;
      if (min=0) or (min>awal) then min:=awal;
      if (max=0) or (max<akhir-1) then max:=akhir-1;
    end;
  maxmilk:=0;
  maxidle:=0;
  k:=min;
  stat:='milk';
  count:=0;
  while not(k>max) do
    begin
      if stat='milk' then
        if (milk[k]) then inc(count)
          else
            begin
              if count>maxmilk then maxmilk:=count;
              stat:='idle';
              count:=1;
            end
        else if not(milk[k]) then inc(count)
          else
            begin
              if count>maxidle then maxidle:=count;
              stat:='milk';
              count:=1;
            end;
      if k=max then if count>maxmilk then maxmilk:=count;
      inc(k);
    end;
  writeln(fout,maxmilk,' ',maxidle);
  close(fin);
  close(fout);
end.
