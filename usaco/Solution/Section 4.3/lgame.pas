{
ID: a_zaky01
PROG: lgame
LANG: PASCAL
}

type
  value=array['a'..'z'] of integer;

const
  score:value=(2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7);

var
  i,j,k,size,n,len,temps,templ,max:longint;
  input,temp:string;
  valid:boolean;
  init,initi,tempv:value;
  count:array[3..7] of longint;
  flag:array[1..3090] of longint;
  words:array[1..10000] of string;
  scr:array[1..10000] of longint;
  fin,fout,dict:text;

label
  closefile;

begin
  assign(fin,'lgame.in');
  assign(fout,'lgame.out');
  assign(dict,'lgame.dict');
  reset(fin);
  rewrite(fout);
  reset(dict);
  readln(fin,input);
  len:=length(input);
  for i:=1 to len do inc(init[input[i]]);
  n:=0;
  max:=0;
  while true do
    begin
      readln(dict,temp);
      if temp='.' then break;
      inc(count[length(temp)]);
      if len<length(temp) then continue;
      valid:=true;
      fillchar(tempv,sizeof(tempv),0);
      temps:=0;
      for i:=1 to length(temp) do
        begin
          inc(tempv[temp[i]]);
          inc(temps,score[temp[i]]);
          if tempv[temp[i]]>init[temp[i]] then
            begin
              valid:=false;
              break;
            end;
        end;
      if valid then
        begin
          inc(n);
          words[n]:=temp;
          scr[n]:=temps;
          if max<temps then max:=temps;
        end;
    end;
  if n=0 then
    begin
      writeln(fout,0);
      goto closefile;
    end;
  writeln(fout,max);
  for i:=1 to n do
    begin
      temps:=scr[i];
      templ:=length(words[i]);
      size:=0;
      if templ+3<=len then
        begin
          fillchar(initi,sizeof(initi),0);
          for j:=1 to templ do inc(initi[words[i][j]]);
          for j:=i to n do
            if templ+length(words[j])<=len then
              begin
                tempv:=initi;
                valid:=true;
                for k:=1 to length(words[j]) do
                  begin
                    inc(tempv[words[j][k]]);
                    if tempv[words[j][k]]>init[words[j][k]] then
                      begin
                        valid:=false;
                        break;
                      end;
                  end;
                if valid then
                  if scr[i]+scr[j]>temps then
                    begin
                      temps:=scr[i]+scr[j];
                      size:=1;
                      flag[size]:=j;
                    end
                  else if scr[i]+scr[j]=temps then
                    begin
                      inc(size);
                      flag[size]:=j;
                      end;
              end;
        end;
      if temps>max then
        begin
          max:=temps;
          rewrite(fout);
          writeln(fout,max);
        end;
      if temps=max then
        if max=scr[i] then writeln(fout,words[i])
          else for j:=1 to size do writeln(fout,words[i],' ',words[flag[j]]);
    end;
  closefile:
  close(fin);
  close(fout);
  close(dict);
end.
