{
ID: a_zaky01
PROG: buylow
LANG: PASCAL
}

uses
  math;

const
  hashv=500000;

var
  n,i,j,ans:longint;
  total:string;
  a,best,hash:array[1..5000] of longint;
  way:array[1..5000] of string;
  used:array[0..hashv-1] of boolean;
  fin,fout:text;

function sum(a,b:string):string;
  var
    k,sisa,n1,n2,x:integer;

  begin
    if length(b)>length(a) then sum:=sum(b,a)
      else
        begin
          n1:=length(a);
          n2:=length(b);
          sisa:=0;
          k:=1;
          sum:='';
          while k<=n1 do
            begin
              x:=ord(a[n1+1-k])-48+sisa;
              if k<=n2 then x:=x+ord(b[n2+1-k])-48;
              sum:=char((x mod 10)+48)+sum;
              if x>9 then sisa:=1
                else sisa:=0;
              inc(k);
            end;
          if sisa<>0 then sum:='1'+sum;
        end;
  end;

begin
  assign(fin,'buylow.in');
  assign(fout,'buylow.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do
    begin
      read(fin,a[i]);
      hash[i]:=a[i] mod hashv;
      way[i]:='0';
    end;
  for i:=1 to n do
    begin
      fillchar(used,sizeof(used),false);
      for j:=i-1 downto 1 do
        if (a[j]>a[i]) and not used[hash[j]] and (best[i]<=best[j]) then
          begin
            used[hash[j]]:=true;
            if best[i]=best[j] then way[i]:=sum(way[i],way[j])
              else
                begin
                  best[i]:=best[j];
                  way[i]:=way[j];
                end;
          end;
      if way[i]='0' then way[i]:='1';
      inc(best[i]);
      ans:=max(best[i],ans);
    end;
  total:='0';
  fillchar(used,sizeof(used),false);
  for i:=n downto 1 do
    if (best[i]=ans) and not used[hash[i]] then
      begin
        total:=sum(total,way[i]);
        used[hash[i]]:=true;
      end;
  writeln(fout,ans,' ',total);
  close(fin);
  close(fout);
end.
