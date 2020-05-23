{
ID: a_zaky01
PROG: wissqu
LANG: PASCAL
}

type
  herd=array[0..5,0..5] of char;
  remm=array[1..4,1..4] of boolean;
  plac=array['A'..'E'] of integer;
  rec=record
    r,c:integer;
    cow:char;
  end;

const
  goal:plac=(3,3,3,4,3);

var
  i,j,i2,j2,count:longint;
  ch,tch:char;
  found,valid:boolean;
  a:herd;
  used:remm;
  curr:plac;
  temp:rec;
  ans:array[0..16] of rec;
  fin,fout:text;

procedure check(p:integer; a:herd; used:remm; curr:plac; temp:rec);
  var
    i,j,i2,j2:integer;
    ch:char;
    valid:boolean;

  begin
    if count=0 then
      begin
        ans[p]:=temp;
        if p=16 then
        for i:=1 to 16 do
          with ans[i] do
            writeln(fout,cow,' ',r,' ',c);
      end;
    if p=16 then
      begin
        inc(count);
        exit;
      end;
    if p>0 then
      with temp do
        begin
          a[r,c]:=cow;
          used[r,c]:=true;
          inc(curr[cow]);
        end;
    for ch:='A' to 'E' do
      if (curr[ch]<goal[ch]) and ((ch='D') or (p>0)) then
        begin
          temp.cow:=ch;
          for i:=1 to 4 do
            for j:=1 to 4 do
              if not used[i,j] then
                begin
                  if a[i,j]=ch then continue;
                  if a[i,j-1]=ch then continue;
                  if a[i,j+1]=ch then continue;
                  if a[i-1,j]=ch then continue;
                  if a[i-1,j-1]=ch then continue;
                  if a[i-1,j+1]=ch then continue;
                  if a[i+1,j]=ch then continue;
                  if a[i+1,j-1]=ch then continue;
                  if a[i+1,j+1]=ch then continue;
                  with temp do
                    begin
                      r:=i;
                      c:=j;
                    end;
                  check(p+1,a,used,curr,temp);
                end;
        end;
  end;

begin
  assign(fin,'wissqu.in');
  assign(fout,'wissqu.out');
  reset(fin);
  rewrite(fout);

  for i:=1 to 4 do
    begin
      for j:=1 to 4 do read(fin,a[i,j]);
      readln(fin);
    end;

  count:=0;

  check(0,a,used,curr,temp);

  writeln(fout,count);

  close(fin);
  close(fout);
end.
