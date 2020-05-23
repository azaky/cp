{
ID: a_zaky01
PROG: namenum
LANG: PASCAL
}

var
  k,i,j,count,temp:integer;
  num:string;
  t:array[2..9] of string;
  name:array[1..5000] of string;
  fin,fout,dict:text;

begin
  assign(fin,'namenum.in');
  assign(fout,'namenum.out');
  assign(dict,'dict.txt');
  reset(fin);
  rewrite(fout);
  reset(dict);
  readln(fin,num);
  k:=0;
  while not(eof(dict)) do
    begin
      inc(k);
      readln(dict,name[k]);
    end;
  t[2]:='ABC';
  t[3]:='DEF';
  t[4]:='GHI';
  t[5]:='JKL';
  t[6]:='MNO';
  t[7]:='PRS';
  t[8]:='TUV';
  t[9]:='WXY';
  count:=0;
  for i:=1 to k do if length(name[i])=length(num) then
    for j:=1 to length(num) do
      begin
        val(num[j],temp);
        if not(pos(name[i][j],t[temp])<>0) then break;
        if j=length(num) then
          begin
            inc(count);
            writeln(fout,name[i]);
          end;
      end;
  if count=0 then writeln(fout,'NONE');
  close(fin);
  close(fout);
  close(dict);
end.