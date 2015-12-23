<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet
	version="1.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/RpcMsgs">
    <html>
    <head>
        <title>GameDB's RPC</title>
    </head>
    <body>
    	<xsl:apply-templates select="RpcServerName"></xsl:apply-templates>
	</body>
	</html>
</xsl:template>

<xsl:variable name="ucase" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'" />
<xsl:variable name="lcase" select="'abcdefghijklmnopqrstuvwxyz'" />

<xsl:template match="RpcServerName">
	<xsl:variable name="serverName" select="@serverName" />
	<xsl:variable name="outputPath" select="@outputPath" />
	
	<xsl:value-of select="@serverName"/>
	<a>
		<xsl:attribute name="href">
			<xsl:value-of select="translate(@outputPath, $ucase, $lcase)"/>
		</xsl:attribute>
		<B>
			服务器生成RPC处理文件路径:
			<xsl:value-of select="@outputPath"/>
		</B>
	</a>
	<br></br>
	
	<!-->处理Client<-->    
	<xsl:for-each select="/RpcMsgs/Rpcs/Rpc">
		<xsl:variable name="rpcName" select="@name" />
		<xsl:for-each select="Targets">			
			<xsl:for-each select="Client">
				<xsl:choose>				
					<xsl:when test="@name = $serverName">						
						<a>
							<xsl:attribute name="href">
								<xsl:choose>				
									<xsl:when test="@class">		
										<xsl:value-of select="$outputPath"/><xsl:value-of select="@class"/>_<xsl:value-of select="$rpcName"/>_Client.cpp
									</xsl:when>
									<xsl:otherwise>
										<xsl:value-of select="$outputPath"/>GlobalRpc_<xsl:value-of select="$rpcName"/>_Client.cpp
									</xsl:otherwise>
								</xsl:choose>
							</xsl:attribute>
							<B>
								<xsl:value-of select="$rpcName"/>
							</B>
						</a>
						<br></br>
					</xsl:when>
				</xsl:choose>
			</xsl:for-each>
		</xsl:for-each>
    </xsl:for-each>
    
	<!-->处理Proxy<-->    
	<xsl:for-each select="/RpcMsgs/Rpcs/Rpc">
		<xsl:variable name="rpcName" select="@name" />
		<xsl:for-each select="Targets">			
			<xsl:for-each select="Proxy">
				<xsl:choose>				
					<xsl:when test="@name = $serverName">						
						<a>
							<xsl:attribute name="href">
								<xsl:choose>				
									<xsl:when test="@class">		
										<xsl:value-of select="$outputPath"/><xsl:value-of select="@class"/>_<xsl:value-of select="$rpcName"/>_Proxy.cpp
									</xsl:when>
									<xsl:otherwise>
										<xsl:value-of select="$outputPath"/>GlobalRpc_<xsl:value-of select="$rpcName"/>_Proxy.cpp
									</xsl:otherwise>
								</xsl:choose>
							</xsl:attribute>
							<B>
								<xsl:value-of select="$rpcName"/>
							</B>
						</a>
						<br></br>
					</xsl:when>
				</xsl:choose>
			</xsl:for-each>
		</xsl:for-each>
    </xsl:for-each>
    
	<!-->处理Server<-->    
	<xsl:for-each select="/RpcMsgs/Rpcs/Rpc">
		<xsl:variable name="rpcName" select="@name" />
		<xsl:for-each select="Targets">			
			<xsl:for-each select="Server">
				<xsl:choose>				
					<xsl:when test="@name = $serverName">						
						<a>
							<xsl:attribute name="href">
								<xsl:choose>				
									<xsl:when test="@class">		
								<xsl:value-of select="$outputPath"/><xsl:value-of select="@class"/>_<xsl:value-of select="$rpcName"/>_Server.cpp
									</xsl:when>
									<xsl:otherwise>
										<xsl:value-of select="$outputPath"/>GlobalRpc_<xsl:value-of select="$rpcName"/>_Server.cpp
									</xsl:otherwise>
								</xsl:choose>
							</xsl:attribute>
							<B>
								<xsl:value-of select="$rpcName"/>
							</B>
						</a>
						<br></br>
					</xsl:when>
				</xsl:choose>
			</xsl:for-each>
		</xsl:for-each>
    </xsl:for-each>
    
	<br></br>
</xsl:template>

<xsl:template match="Rpcs">
	Rpc:
	<xsl:apply-templates select="Rpc"></xsl:apply-templates>
	<br></br> 
</xsl:template>

<xsl:template match="Rpcs/Rpc">
	<li>
		<a>
			<xsl:attribute name="href">
				<xsl:value-of select="translate(../@name, $ucase, $lcase)"/>\
				<xsl:value-of select="translate(@name, $ucase, $lcase)"/>.cpp
			</xsl:attribute>
			<xsl:value-of select="@name" />
		</a>
		<br></br> 
		<xsl:apply-templates select="Targets"></xsl:apply-templates>
	</li> 
</xsl:template>

<xsl:template match="Rpcs/Rpc/Targets">
	<xsl:value-of select="@name" />
	<xsl:apply-templates select="Client"></xsl:apply-templates>
	<xsl:apply-templates select="Proxy"></xsl:apply-templates>
	<xsl:apply-templates select="Server"></xsl:apply-templates>	
</xsl:template>

<xsl:template match="Rpcs/Rpc/Targets/Client">
	<xsl:value-of select="@name" />
	<br></br> 
</xsl:template>

<xsl:template match="Rpcs/Rpc/Targets/Proxy">
	<xsl:value-of select="@name" />
	<br></br> 
</xsl:template>

<xsl:template match="Rpcs/Rpc/Targets/Server">
	<xsl:value-of select="@name" />
	<br></br> 
</xsl:template>


</xsl:stylesheet>

 
