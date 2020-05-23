{
ID: a_zaky01
PROG: charrec
LANG: PASCAL
}

const
  maxfont = 540;
  maxn = 1201;
  maxc = 20000;
  tolerance = 120;

var
  n,i,j,k,temp:integer;
  s:string[20];
  letter:array[0..26] of char;
  font:array[1..maxfont] of string[20];
  diff:array[1..maxn,1..maxfont] of integer;
  x:array[1..maxn,19..21] of integer;
  pred:array[1..maxn,19..21] of char;
  corrupt:array[1..maxn] of integer;
  seq:array[1..maxn] of string;
  f:text;

procedure check(pos,len:integer);
  var
    k,temp,i:integer;
  
  procedure compare;
    begin
      if temp<x[pos,len] then
        begin
          if temp<=tolerance then pred[pos,len]:=letter[k]
            else pred[pos,len]:='?';
          x[pos,len]:=temp;
        end
      else if temp=x[pos,len] then
        if letter[k]<>pred[pos,len] then pred[pos,len]:='?';
    end;
    
  begin
    x[pos,len]:=maxc;
    for k:=0 to 26 do
      case len of
        19 : begin
               temp:=0;
               for i:=1 to 19 do temp:=temp+diff[pos+i-1,k*20+i];
               compare;
               for i:=19 downto 1 do
                 begin
                   temp:=temp-diff[pos+i-1,k*20+i]+diff[pos+i-1,k*20+i+1];
                   compare;
                 end;
             end;
        21 : begin
               temp:=0;
               for i:=1 to 21 do temp:=temp+diff[pos+i-1,k*20+i];
               compare;
               for i:=21 downto 1 do
                 begin
                   temp:=temp-diff[pos+i-1,20*k+i]+diff[pos+i,k*20+i];
                   compare;
                 end;
             end;
        20 : begin
               temp:=0;
               for i:=1 to 20 do temp:=temp+diff[pos+i-1,k*20+i];
               compare;
             end;
      end;
  end;

begin

  assign(input,'charrec.in'); reset(input);
  assign(output,'charrec.out'); rewrite(output);
  assign(f,'font.in'); reset(f);
  
  //setup the letter table
  letter[0]:=' ';
  for i:=1 to 26 do letter[i]:=chr(ord('a')-1+i);
  
  //read the input from 'font.in'
  readln(f,n);
  for i:=1 to maxfont do readln(f,font[i]);
  
  //read the input from 'charrec.in' and compute the number of difference with the file 'font.in'
  readln(n);
  fillchar(diff,sizeof(diff),0);
  for i:=1 to n do
    begin
      readln(s);
      for j:=1 to maxfont do
        for k:=1 to 20 do
          if s[k]<>font[j][k] then inc(diff[i,j]);
    end;
  
  for i:=1 to n do seq[i]:='';
  
  //setup the x and pred table
  for i:=19 to 21 do
    begin
      for j:=1 to n-i+1 do check(j,i);
      seq[i]:=pred[1,i];
      corrupt[i]:=x[1,i];
    end;
  
  //predicting the best possible sequence based on the number of the corruptions
  for i:=38 to n do
    begin
      corrupt[i]:=maxc;
      for j:=19 to 21 do
        if length(seq[i-j])>0 then
          begin
            temp:=corrupt[i-j]+x[i-j+1,j];
            if temp<corrupt[i] then
              begin
                corrupt[i]:=temp;
                seq[i]:=seq[i-j]+pred[i-j+1,j];
              end;
          end;
    end;
  
  writeln(seq[n]);
  
  close(input);
  close(output);
  close(f);
  
end.

