var app = {
    // Application Constructor
    initialize: function() {
	
	
		var url01On  = "http://xx/relay01/on";
		var url01Off = "http://xx/relay01/off";
		
		var url02On  = "http://xx/relay02/on";
		var url02Off = "http://xx/relay02/off";
        
		$("#button01On").click(function(){
			
            $.ajax({
                url: url01On,
                success: handleResponse
            });
			//console.log(urlOn);
            
            function handleResponse(){
				//$("#button01On").attr("disabled","disabled");
				//$("#button01Off").removeAttr("disabled");
			}
			
        });
		
		$("#button01Off").click(function(){
			
            $.ajax({
                url: url01Off,
                success: handleResponse
            });
			//console.log(urlOff);
            
            function handleResponse(){
				//$("#button01On").removeAttr("disabled");
				//$("#button01Off").attr("disabled","disabled");
			}
			
        });
		
			$("#button02On").click(function(){
			
            $.ajax({
                url: url02On,
                success: handleResponse
            });
			//console.log(urlOn);
            
            function handleResponse(){
				//$("#button02On").attr("disabled","disabled");
				//$("#button02Off").removeAttr("disabled");
			}
			
        });
		
		$("#button02Off").click(function(){
			
            $.ajax({
                url: url02Off,
                success: handleResponse
            });
			//console.log(urlOff);
            
            function handleResponse(){
				//$("#button02On").removeAttr("disabled");
				//$("#button02Off").attr("disabled","disabled");
			}
			
        });
    },
};

app.initialize();