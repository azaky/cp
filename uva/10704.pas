type
  arr = array[-3..8,-3..8] of integer;
  traffic = record
    mark:arr;
	rw,cw,move,last:integer;
	v2,v3,h2,h3:array[1..5,1..2] of integer;
  end;

var
  tc,kasus,r,c,nv2,nv3,nh2,nh3,i,k,ans:integer;
  qtake,qsave:longint;
  temp,temp2:traffic;
  queue:array[1..10000000] of traffic;

label
  answer;

function occ(mark:arr; r,c:integer):boolean;
  begin
	exit(not ((mark[r,c]=-1) and not (mark[r-1,c] in [1,2]) and (mark[r-2,c]<>2) and not (mark[r,c-1] in [0,3,4]) and (mark[r,c-2]<>4)));
  end;

function found(a:traffic):boolean;
  var
    i,j,k:integer;
	same:boolean;
  
  begin
    for k:=1 to qsave do
	  begin
	    same:=true;
		for i:=0 to 5 do
		  begin
		    for j:=0 to 5 do
			  if a.mark[i,j]<>queue[k].mark[i,j] then
			    begin
				  same:=false;
				  break;
				end;
			if not same then break;
		  end;
		if same then exit(true);
	  end;
	exit(false);
  end;

begin
  readln(tc);
  for kasus:=1 to tc do
    begin
	  with queue[1] do
	    begin
    	  fillchar(mark,sizeof(mark),255);
		  //the marks are:
		  //-1 for nothing
		  //0 for white block
		  //1 for vertical-2
		  //2 for vertical-3
		  //3 for horizontal-2
		  //4 for horizontal-3
    	  readln(rw,cw); mark[rw,cw]:=0;
    	  read(nv2);
    	  for i:=1 to nv2 do
	        begin
    		  read(r,c); v2[i][1]:=r; v2[i][2]:=c;
			  mark[r,c]:=1;
    		end;
    	  read(nv3);
    	  for i:=1 to nv3 do
    	    begin
    		  read(r,c); v3[i][1]:=r; v3[i][2]:=c;
			  mark[r,c]:=2;
    		end;
    	  read(nh2);
    	  for i:=1 to nh2 do
    	    begin
    		  read(r,c); h2[i][1]:=r; h2[i][2]:=c;
			  mark[r,c]:=3;
    		end;
    	  read(nh3);
    	  for i:=1 to nh3 do
    	    begin
    		  read(r,c); h3[i][1]:=r; h3[i][2]:=c;
			  mark[r,c]:=4;
    		end;
		  move:=0; last:=-1;
		end;
	  qtake:=1; qsave:=1;
	  repeat
	    writeln(qtake,' ',qsave);
	    temp:=queue[qtake]; inc(temp.move);
	    with queue[qtake] do
		  begin
		    //move the white block
			if last<>0 then
			  begin
			    temp.last:=0;
			    for i:=cw-1 downto 0 do
			      begin
			        if occ(mark,rw,i) then break;
				    temp2:=temp;
				    temp2.mark[rw,cw]:=-1; temp2.mark[rw,i]:=0; temp2.cw:=i;
				    if found(temp2) then continue;
				    inc(qsave); queue[qsave]:=temp2;
			      end;
			    for i:=cw+1 to 4 do
			      begin
			        if occ(mark,rw,i+1) then break
				      else if i=4 then
				        begin
					      ans:=temp.move; goto answer;
					    end;
				    temp2:=temp;
				    temp2.mark[rw,cw]:=-1; temp2.mark[rw,i]:=0; temp2.cw:=i;
				    if found(temp2) then continue;
				    inc(qsave); queue[qsave]:=temp2;
			      end;
			  end;
			//move the vertical-2
			for k:=1 to nv2 do
			  begin
			    if last=10+k then continue else temp.last:=10+k;
			    r:=v2[k][1]; c:=v2[k][2];
			    for i:=r-1 downto 0 do
				  begin
				    if occ(mark,i,c) then break;
					temp2:=temp;
					temp2.mark[r,c]:=-1; temp2.mark[i,c]:=1; temp2.v2[k][1]:=i;
					if found(temp2) then continue;
					inc(qsave); queue[qsave]:=temp2;
				  end;
				for i:=r+1 to 4 do
				  begin
				    if occ(mark,i+1,c) then break;
					temp2:=temp;
					temp2.mark[r,c]:=-1; temp2.mark[i,c]:=1; temp2.v2[k][1]:=i;
					if found(temp2) then continue;
					inc(qsave); queue[qsave]:=temp2;
				  end;
			  end;
			//move the vertical-2
			for k:=1 to nv3 do
			  begin
			    if last=20+k then continue else temp.last:=20+k;
			    r:=v3[k][1]; c:=v3[k][2];
			    for i:=r-1 downto 0 do
				  begin
				    if occ(mark,i,c) then break;
					temp2:=temp;
					temp2.mark[r,c]:=-1; temp2.mark[i,c]:=2; temp2.v3[k][1]:=i;
					if found(temp2) then continue;
					inc(qsave); queue[qsave]:=temp2;
				  end;
				for i:=r+1 to 3 do
				  begin
				    if occ(mark,i+2,c) then break;
					temp2:=temp;
					temp2.mark[r,c]:=-1; temp2.mark[i,c]:=2; temp2.v3[k][1]:=i;
					if found(temp2) then continue;
					inc(qsave); queue[qsave]:=temp2;
				  end;
			  end;
			//move the horiontal-2
			for k:=1 to nh2 do
			  begin
			    if last=30+k then continue else temp.last:=30+k;
			    r:=h2[k][1]; c:=h2[k][2];
				for i:=c-1 downto 0 do
				  begin
				    if occ(mark,r,i) then break;
					temp2:=temp;
					temp2.mark[r,c]:=-1; temp2.mark[r,i]:=3; temp2.h2[k][2]:=i;
					if found(temp2) then continue;
					inc(qsave); queue[qsave]:=temp2;
				  end;
				for i:=c+1 to 4 do
				  begin
				    if occ(mark,r,i+1) then break;
					temp2:=temp;
					temp2.mark[r,c]:=-1; temp2.mark[r,i]:=3; temp2.h2[k][2]:=i;
					if found(temp2) then continue;
					inc(qsave); queue[qsave]:=temp2;
				  end;
			  end;
			//move the horizontal-3
			for k:=1 to nh3 do
			  begin
			    if last=40+k then continue else temp.last:=40+k;
			    r:=h3[k][1]; c:=h3[k][2];
				for i:=c-1 downto 0 do
				  begin
				    if occ(mark,r,i) then break;
					temp2:=temp;
					temp2.mark[r,c]:=-1; temp2.mark[r,i]:=4; temp2.h3[k][2]:=i;
					if found(temp2) then continue;
					inc(qsave); queue[qsave]:=temp2;
				  end;
				for i:=c+1 to 3 do
				  begin
				    if occ(mark,r,i+2) then break;
					temp2:=temp;
					temp2.mark[r,c]:=-1; temp2.mark[r,i]:=4; temp2.h3[k][2]:=i;
					if found(temp2) then continue;
					inc(qsave); queue[qsave]:=temp2;
				  end;
			  end;
		  end;
		inc(qtake);
	  until qtake>qsave;
	  answer:
	  writeln(qtake,' ',qsave);
	  writeln('The minimal number of moves to solve puzzle ',kasus,' is ',ans,'.');
	end;
end.
